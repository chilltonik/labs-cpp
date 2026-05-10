#include "List.h"
using namespace std;

int main()
{
	List<Game> lst;
	lst.fill();
	lst.print();

	List<Game> lst2 = lst;
	lst2.print();

	return 0;
}