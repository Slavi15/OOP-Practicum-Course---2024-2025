<h1 align="center">ООП - Практикум - 24.02.2025 - Седмица 01</h1>

## 0. Малко пойнтъри

**Задача 1:**

```c++
#include <iostream>

int main()
{
	int a = 10;
	int b = 20;

	const int* ptr1 = &a;
	int* const ptr2 = &b;

	ptr1 = &b;
	// *ptr1 = 20; // Не можем да променяме данните, към които сочи ptr1

	// ptr2 = &b; // Не можем да пренасочваме ptr2 към друг указател
	*ptr2 = 30;

	return 0;
}
```

**Задача 2:** Какво ще се отпечата на конзолата?

```c++
int * ptrInt = new int[3];
char* ptrCH = new char[7];
std::cout << (sizeof(ptrInt) == sizeof(ptrCH));
```

**Задача 3:** Какво ще се отпечата на конзолата?

```c++
#include <iostream>

void f(char)
{
	std::cout << "char";
}

void f(char*)
{
	std::cout << "char*";
}

void f(char**)
{
	std::cout << "char**";
}

int main()
{
	char* ptr;
	f(&ptr);

	return 0;
}
```

## 1. Namespaces

- Пространство от имена
- Използват се за избягване на колизии от имена

### Синтаксис - namespace < ns-name > { }

### Извикване:

- **< ns-name >::f()** - еднократно извикване на функция **f()**, обвита в дадения namespace, чрез оператора за резолюция
- **using < ns-name >::f()** - в рамките на текущия scope можем да извикваме функцията **f()** без оператор за резолюция
- **using namespace < ns-name >** - в рамките на текущия scope можем да извикаме всички методи в дадения namespace

**Задача 4:** Какво ще се отпечата на конзолата при следното парче код?

```c++
#include <iostream>

namespace A
{
	void f()
	{
		std::cout << 'A' << std::endl;
	}
}

namespace B
{
	void f()
	{
		std::cout << 'B' << std::endl;
	}
}

int main()
{
	using namespace A;
	using namespace B;

	f();

	return 0;
}
```

## 2. Enums

- Тип, рестриктиран до домейн от стойности, включващи специално дефинирани константи
- Каква е разликата между **enum** и **enum class**?
- Всеки енумератор отговаря на цяло число, като ако такова не е указано => [ предния + 1 ]
- Ако не е указано, първият енумератор по default има стойност 0

**Задача 5:** На какво число отговаря всеки енумератор в дадения enum?

```c++
enum Test
{
	a,
	b,
	c = 5,
	d,
	e = 4,
	f,
	g = a + b
};
```

## 3. Structs

### Размер на обекти / инстанции:
- Подравняване по най-големия примитивен тип
- Размерът на цялата структура трябва да се дели на най-големия примитивен тип
- Всяка член-данна се намира на адрес, кратен на размера ѝ

**Задача 6:** Какви са размерите и подравняването на всяка от структурите?

```c++
struct Empty {
};

struct Test1
{
	int number;
};

struct Test2
{
	char symbol;
	int number;
};

struct Test3
{
	char symbol;
	short sh;
	int number;
};

struct Test4
{
	char symbol1;
	int number;
	char symbol2;
};

struct Student
{
	char* name;
	int* grades;
};

struct Test5
{
	char a[5];
	int b;
	double c;
};

struct Test6
{
	char a[3];
	short b;
	double c[4];
	char d;
};

struct Test7
{
	int number;
	char symbol;
	char chArr[];
};

struct Test8
{
	size_t x;
	char (*pred)(char, char);
	char ch;
};
```

```c++
struct A
{
	double c;
	char b;
};

struct B
{
	char c;
};

struct C
{
	A obj;
	B obj2;
};
```

```c++
struct A
{
	int a;
	char b;
};

struct B
{
	char c;
};

struct C
{
	char f;
	A obj;
	B obj2;
	double d;
};
```

## 4. Връщане на структури от функция

```c++
A f()
{
	A obj;
	// ...
	return obj; // OK
}
```

```c++
A& f()
{
	A obj;
	// ...
	return obj; // obj умира в края на scope-a. НЕ го правим
}
```

```c++
const A& f()
{
	A obj;
	// ...
	return obj; // const удължава живота на obj, но НЕ го правим
}
```

```c++
A* f()
{
	A* ptr = new A();
	// ...
	return ptr; // OK
}
```

```c++
A* f()
{
	A obj;
	// ...
	return &obj; // obj умира в края на scope-a. НЕ го правим
}
```

## 5. Подаване на структури като параметри във функции

- Във функции, структури се подават по референция, константна референция, указател, константен указател, но **НЕ** и по копие, защото е тежка операция
- Ако ще променяме данните - по референция / указател
- Ако **няма** да променяме данните - по константна референция / указател
