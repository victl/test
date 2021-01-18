#include <iostream>

#include "ceres/ceres.h"
#include "glog/logging.h"

struct CostFunctor
{
  template <typename T>
  bool operator()(const T *const x, T *residual) const
  {
    residual[0] = 10.0 - x[0];
    return true;
  }
};

struct NumericDiffCostFunctor
{
  bool operator()(const double *const x, double *residual) const
  {
    residual[0] = 10.0 - x[0];
    return true;
  }
};

class QuadraticCostFunction : public ceres::SizedCostFunction<1, 1>
{
public:
  virtual ~QuadraticCostFunction() {}
  virtual bool Evaluate(double const *const *parameters,
                        double *residuals,
                        double **jacobians) const
  {
    const double x = parameters[0][0];
    residuals[0] = 10 - x;

    if (jacobians && jacobians[0])
    {
      jacobians[0][0] = -1;
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  google::InitGoogleLogging(argv[0]);
  double x = 0.5;
  const double initial_x = x;
  ceres::Problem problem;
  // // method 1: auto diff
  // ceres::CostFunction *cost_function =
  //     new ceres::AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor);

  // // method 2: numeric diff
  // ceres::CostFunction *cost_function =
  //     new ceres::NumericDiffCostFunction<NumericDiffCostFunctor, ceres::CENTRAL, 1, 1>(
  //         new NumericDiffCostFunctor);

  // // method 3: self provided cost function
  ceres::CostFunction *cost_function = new QuadraticCostFunction;
  problem.AddResidualBlock(cost_function, nullptr, &x);

  ceres::Solver::Options options;
  options.minimizer_progress_to_stdout = true;
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  std::cout << summary.BriefReport() << "\n"
            << "x: " << initial_x << " -> " << x << "\n";
  return 0;
}
