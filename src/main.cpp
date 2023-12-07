

#include "ipp/Core/Core.hpp"
int main(const int argc, const char** argv)
{
  if (argc != 2)
    return 1;
  Ipp::Core* core = new Ipp::Core();

  if (!core->initImage(argv[1]))
  {
    delete core;
    return 1;
  }
  core->run();
  delete core;
  return 0;
}