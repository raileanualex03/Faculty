# include <cassert>
# include "domain.h"
# include "DynamicVector.h"
# include "controller.h"
#include <iostream>

// the tests for the domain
void test_getID__GoodInput__ReturnsID();

void test_getSize__GoodInput__ReturnsSize();

void test_getRadioactivityLevel__GoodInput__ReturnsRadioactivityLevel();

void test_getQuantityOfMicrofragments__GoodInput__ReturnsValue();

void test_getDigitizedScan__GoodInput__ReturnsValue();

void test_ToString__GoodInput__ReturnsString();

void testDomain();

// tests for dynamicVector
void test__addElement__GoodInput__Returns1();

void test__addElement__BadInput__Returns0();

void test__removeElement__GoodInput__Returns1();

void test__removeElement__BadInput__Returns0();

void test__getSize__GoodInput__ReturnsValue();

void test__searchElement__GoodInput__ReturnsBot();

void testDynamicVector();

// tests for repository in file 
void file_test__addBot__GoodInput__Returns1();

void file_test__addBot__BadInput__Returns0();

void file_test__removeBot__GoodInput__Returns1();

void file_test__removeBot__BadInput__Returns0();

void file_test__updateBot__GoodInput__Returns1();

void file_test__updateBot__BadInput__Returns0();

void file_test__searchBot__GoodInput__ReturnsBot();

void file_test__existsBot__GoodInput__Returns1();

void file_test__existsBot__BadInput__Returns0();

void file_test__setFilename__GoodInput__Returns1();

void testRepositoryFiles();



// tests for repository in memory

void test__addBot__GoodInput__Returns1();

void test__addBot__BadInput__Returns0();

void test__removeBot__GoodInput__Returns1();

void test__removeBot__BadInput__Returns0();

void test__updateBot__GoodInput__Returns1();

void test__updateBot__BadInput__Returns0();

void test__searchBot__GoodInput__ReturnsBot();

void test__existsBot__GoodInput__Returns1();

void test__existsBot__BadInput__Returns0();


void testRepositoryMemory();

// these are the tests for the controller
void test_controllerAddBot__GoodInput__Returns1();

void test_controllerAddBot__BadInput__Returns0();

void test_controllerRemoveBot__GoodInput__Returns1();

void test_controllerRemoveBot__BadInput__Returns0();

void test_controllerUpdateBot__GoodInput__Returns1();

void test_controllerUpdateBot__BadInput__Returns01();

void test_controllerUpdateBot__BadInput__Returns02();

void test_controllerGetAll__NoInput_ReturnsAll();

void test_assistantAddBot__GoodInput__Returns1();

void test_nextBot__NoInput__ReturnsNextBot();

void test_nextBot_nextBot__NoInput__ReturnsFirstBot();

void test_assistantGetBots__NoInput__ReturnsAllBots();

void test_setFilename__GoodInput__Returns1();

void testController();

// these are the tests for the validator :)

void test_checkID__GoodInput__ReturnsTrue();

void test_checkSize__GoodInput__ReturnsTrue();

void test_checkSize__BadInput__ReturnsFalse();

void test_checkRadioactivityLevel__GoodInput__ReturnsTrue();

void test_checkRadioactivityLevel__BadInput__ReturnsFalse1();

void test_checkRadioactivityLevel__BadInput__ReturnsFalse2();

void test_checkQuantityOfMicrofragments__GoodInput__ReturnsTrue();

void test_checkDigitizedScan__GoodInput__ReturnsTrue();

void testValidator();


// this will contain all the tests
void testAll();