#include <iostream>
#include <vector>
#include <CGAL/Cartesian_d.h>
#include <CGAL/point_generators_d.h>
#include <CGAL/constructions_d.h>

typedef CGAL::Cartesian_d<double> Kd;
typedef Kd::Point_d Point;
typedef CGAL::Creator_uniform_d <std::vector<double>::iterator, Point> Creator_d;

int main (int argc, char const *argv[])
{
  int nb_points = 250;
  int dim = 3;
  double size = 1.0;
  std::cout << "Generating " << nb_points << " grid points in "
            << dim << "D" << std::endl;
  std::vector<Point> v;
  v.reserve(nb_points);
  CGAL::points_on_cube_grid_d (dim, size, (std::size_t) nb_points,
        std::back_inserter(v), Creator_d(dim) );

  for(size_t i = 0; i < nb_points; ++i) std::cout<<" "<< v[i] << std::endl;
  return 0;
}
