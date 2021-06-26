// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTest.h"
#include <type_traits>
#include <iostream>



using namespace std;

void PrintV(int&& t) {
	UE_LOG(LogTemp, Warning, TEXT("rvalue"));
}

void PrintV(int& t) {
	UE_LOG(LogTemp, Warning, TEXT("lvalue"));
}

// void PrintV(int&& t) {
// 	UE_LOG(LogTemp, Warning, TEXT("rvalue"));
// }


template<typename T>
void Test(T&& t) {
	// t是一个有名字的变量，是个左值

	PrintV(t);

	// 完美转发：forward返回的左还是右取决于T，所以实际上是取决于调用Test()时候的实参的类型
	PrintV(std::forward<T>(t));

	// move返回的一定是右值引用，也是一个将亡值(​expiring value)
	PrintV(std::move(t));
}

void LRValueTest() {
	Test(1); // lvalue rvalue rvalue

	int a = 1;
	Test(a); // lvalue lvalue rvalue
	Test(std::forward<int>(a)); // lvalue rvalue rvalue
	Test(std::forward<int&>(a)); // lvalue lvalue rvalue
	Test(std::forward<int&&>(a)); // lvalue rvalue rvalue
}