#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

int  ft_is_in(int *tab, int nb)
{
  int i;

  i = 0;
  while(tab[i] != -2000000000)
  {
    if (tab[i] == nb)
      return 1;
    i++;
  }
  return (0);
}

int  main(int nb, char **arg)
{
  int  size = atoi(arg[1]);
  int  n = 0;
  int  val;
  srand(time(NULL));

  std::cout << nb << std::endl;
  if (nb)
  {
    std::ofstream  ofs("test_push_swap.sh");
    ofs << "./push_swap ";
    int  tab[size];
    while (n < size)
    {
      tab[n] = -2000000000;
      n++;
    }
    n = 0;
    while (n < size)
    {
      val = (rand() % 2100000000) - 1050000000;
      if (!ft_is_in(tab, val))
      {
        tab[n] = val;
        ofs << val << " ";
        n++;
      }
    }
    ofs << "| ./checker";
    n = 0;
    while (n < size)
    {
      ofs << " " << tab[n];
      n++;
    }
    ofs << std::endl << "./push_swap";
    n = 0;
    while (n < size)
    {
      ofs << " " << tab[n];
      n++;
    }
    ofs << " | wc -l" << std::endl;
    ofs.close();
  }
  return (0);
}
