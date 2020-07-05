//# include "tests.h"
//#include "repositoryFiles.h"
//
//
//// these are the tests for the domain
//void test_getID__GoodInput__ReturnsID()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.getID() == ID);
//};
//void test_getSize__GoodInput__ReturnsSize()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.getSize() == size);
//};
//void test_getRadioactivityLevel__GoodInput__ReturnsRadioactivityLevel()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.getRadioactivityLevel() == radioactivityLevel);
//};
//void test_getQuantityOfMicrofragments__GoodInput__ReturnsValue()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.getQuantityOfMicrofragments() == quantityOfMicroframgnets);
//};
//void test_getDigitizedScan__GoodInput__ReturnsValue()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.getDigitizedScan() == digitizedScan);
//}
//void test_ToString__GoodInput__ReturnsString()
//{
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(bot.ToString().length(), 103);
//}
//;
//void testDomain()
//{
//	std::cout << "Info: currently running tests for domain ...\n";
//	test_getID__GoodInput__ReturnsID();
//	test_getSize__GoodInput__ReturnsSize();
//	test_getRadioactivityLevel__GoodInput__ReturnsRadioactivityLevel();
//	test_getQuantityOfMicrofragments__GoodInput__ReturnsValue();
//	test_getDigitizedScan__GoodInput__ReturnsValue();
//	test_ToString__GoodInput__ReturnsString();
//	std::cout << "Result: the tests are fine!     :)\n";
//}
//void test__addElement__GoodInput__Returns1()
//{		
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = vector.addElement(bot);
//	assert(result == 1);
//
//}
//
//void test__addElement__BadInput__Returns0()
//{
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	vector.addElement(bot);
//	unsigned result = vector.addElement(bot);
//	assert(result == 0);
//}
//
//void test__removeElement__GoodInput__Returns1()
//{
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	vector.addElement(bot);
//	unsigned result = vector.deleteElement(bot.getID());
//	assert(result == 1);
//}
//
//void test__removeElement__BadInput__Returns0()
//{
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = vector.deleteElement(bot.getID());
//	assert(result == 0);
//}
//
//void test__getSize__GoodInput__ReturnsValue()
//{
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	vector.addElement(bot);
//	unsigned result = vector.getSize();
//	assert(result == 1);
//}
//
//void test__searchElement__GoodInput__ReturnsBot()
//{
//	DynamicVector<Bot> vector = DynamicVector<Bot>();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	vector.addElement(bot);
//	Bot botFound = vector.searchElement(ID);
//	assert(botFound.getID() == ID);
//}
//
//
//
//// these are the tests for the dynamicVector
//
//void testDynamicVector()
//{
//	std::cout << "\nInfo: currently running tests for the dynamicVector ...\n";
//	test__addElement__GoodInput__Returns1();
//	test__addElement__BadInput__Returns0();
//	test__removeElement__GoodInput__Returns1();
//	test__removeElement__BadInput__Returns0();
//	test__getSize__GoodInput__ReturnsValue();
//	test__searchElement__GoodInput__ReturnsBot();
//	std::cout << "Result: the tests are fine!     :)\n";
//}
//
//void file_test__addBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot2 = Bot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.addBot(bot);
//	assert(result == 1);
//	remove(text);
//}
//
//void file_test__addBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	unsigned result = repo.addBot(bot);
//	assert(result == 0);
//
//	remove(text);
//
//}
//
//void file_test__removeBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string ID3 = "f4833";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot2 = Bot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot3 = Bot(ID3, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	repo.addBot(bot2);
//	repo.addBot(bot3);
//	unsigned result = repo.removeBot(bot);
//	assert(result == 1);
//
//	remove(text);
//}
//
//void file_test__removeBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4835";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.removeBot(bot);
//	assert(result == 0);
//
//	remove(text);
//}
//
//
//void file_test__updateBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	unsigned result = repo.updateBot(bot);
//	assert(result == 1);
//	remove(text);
//}
//
//void file_test__updateBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.updateBot(bot);
//	assert(result == 0);
//	remove(text);
//}
//
//void file_test__searchBot__GoodInput__ReturnsBot()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	Bot bot2 = Bot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot2);
//	Bot result = repo.searchBot(bot2.getID());
//	assert(result.getID() == bot2.getID());
//
//	remove(text);
//}
//
//void file_test__existsBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	unsigned result = repo.existsBot(bot.getID());
//	assert(result == 1);
//
//	remove(text);
//}
//
//void file_test__existsBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4833";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.existsBot(bot.getID());
//	assert(result == 0);
//
//	remove(text);
//}
//
//void file_test__setFilename__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string filename = "newinput.txt";
//	unsigned result = repo.setFilename(filename);
//	assert(result == 1);
//}
//
//void testRepositoryFiles()
//{
//	std::cout << "\nInfo: currently running tests for repository files...\n";
//	file_test__addBot__GoodInput__Returns1();
//	file_test__addBot__BadInput__Returns0();
//	file_test__removeBot__BadInput__Returns0();
//	file_test__removeBot__GoodInput__Returns1();
//	file_test__updateBot__GoodInput__Returns1();
//	file_test__updateBot__BadInput__Returns0();
//	file_test__searchBot__GoodInput__ReturnsBot();
//	file_test__existsBot__BadInput__Returns0();
//	file_test__existsBot__GoodInput__Returns1();
//	file_test__setFilename__GoodInput__Returns1();
//	std::cout << "Result: the tests are fine!     :)\n";
//
//}
//
//void test__addBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryMemory repo = RepositoryMemory(); 
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.addBot(bot);
//	assert(result == 1);
//}
//
//void test__addBot__BadInput__Returns0()
//{
//
//	char text[32] = "text.txt";
//	RepositoryMemory repo = RepositoryMemory();
//	std::string ID = "f4839";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan); 
//	repo.addBot(bot);
//	unsigned result = repo.addBot(bot);
//	assert(result == 0);
//}
//
//void test__removeBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt";
//	RepositoryMemory repo = RepositoryMemory(); 
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string ID3 = "f4833";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot2 = Bot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot3 = Bot(ID3, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	repo.addBot(bot2);
//	repo.addBot(bot3);
//	unsigned result = repo.removeBot(bot3);
//	assert(result == 1);
//
//}
//
//void test__removeBot__BadInput__Returns0()
//{
//
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.removeBot(bot);
//	assert(result == 0);
//}
//
//void test__updateBot__GoodInput__Returns1()
//{
//
//	char text[32] = "text.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	unsigned result = repo.updateBot(bot);
//	assert(result == 1);
//}
//
//void test__updateBot__BadInput__Returns0()
//{
//
//	char text[32] = "text.txt";
//	RepositoryMemory repo = RepositoryMemory();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.updateBot(bot);
//	assert(result == 0);
//}
//
//void test__searchBot__GoodInput__ReturnsBot()
//{
//	RepositoryMemory repo = RepositoryMemory();
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	Bot bot2 = Bot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	repo.addBot(bot2);
//	Bot result = repo.searchBot(ID2);
//	assert(result.getID() == ID2);
//}
//
//void test__existsBot__GoodInput__Returns1()
//{
//	RepositoryMemory repo = RepositoryMemory();
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	repo.addBot(bot);
//	unsigned result = repo.existsBot(bot.getID());
//	assert(result == 1);
//}
//
//void test__existsBot__BadInput__Returns0()
//{
//	RepositoryMemory repo = RepositoryMemory();
//	std::string ID = "f48301234";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	Bot bot = Bot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = repo.existsBot(bot.getID());
//	assert(result == 0);
//}
//
//// these are the tests for the repository in memory:)
//
//
//void testRepositoryMemory()
//{
//	std::cout << "\nInfo: currently running tests for the repository ...\n";
//	test__addBot__GoodInput__Returns1();
//	test__addBot__BadInput__Returns0();
//	test__removeBot__GoodInput__Returns1();
//	test__removeBot__BadInput__Returns0();
//	test__updateBot__GoodInput__Returns1();
//	test__updateBot__BadInput__Returns0();
//	test__searchBot__GoodInput__ReturnsBot();
//	test__existsBot__BadInput__Returns0();
//	test__existsBot__GoodInput__Returns1();
//	std::cout << "Result: the tests are fine!     :)\n";
//
//}
//
//void test_controllerAddBot__GoodInput__Returns1()
//{
//
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4832";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	unsigned result = controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(result == 1);
//
//	remove(text);
//}
//
//void test_controllerAddBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X2010";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(result == 0);
//
//	remove(text);
//}
//
//void test_controllerRemoveBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = controller.removeBot(ID);
//	assert(result == 1);
//
//	remove(text);
//}
//
//void test_controllerRemoveBot__BadInput__Returns0()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	unsigned result = controller.removeBot(ID);
//	assert(result == 0);
//
//	remove(text);
//}
//
//
//void test_controllerUpdateBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = controller.updateBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(result == 1);
//
//	remove(text);
//}
//
//void test_controllerUpdateBot__BadInput__Returns01()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	unsigned result = controller.updateBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(result == 0);
//
//	remove(text);
//}
//
//void test_controllerUpdateBot__BadInput__Returns02()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4832";
//	std::string ID2 = "f4839";
//	std::string size = "0xxxxx";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = controller.updateBot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	assert(result == 0);
//
//	remove(text);
//}
//
//void test_controllerGetAll__NoInput_ReturnsAll()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	std::vector<Bot> result = controller.getElements();
//	assert(result.size() == 1);
//
//	remove(text);
//}
//
//void test_assistantAddBot__GoodInput__Returns1()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	unsigned result = controller.assistantAddBot(ID);
//
//	remove(text);
//}
//
//
//
//void test_nextBot__NoInput__ReturnsNextBot()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	
//	Bot nextBot = controller.getNextBot();
//	assert(ID == nextBot.getID());
//
//	remove(text);
//}
//
//void test_nextBot_nextBot__NoInput__ReturnsFirstBot()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string ID2 = "f4832";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	controller.addBot(ID2, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	controller.getNextBot();
//	controller.getNextBot();
//	Bot nextBot = controller.getNextBot();
//	assert(ID == nextBot.getID());
//
//	remove(text);
//
//}
//
//void test_assistantGetBots__NoInput__ReturnsAllBots()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	std::string ID = "f4831";
//	std::string size = "40X20X10";
//	std::string radioactivityLevel = "300";
//	double quantityOfMicroframgnets = 300;
//	std::string digitizedScan = "A#E21";
//	controller.addBot(ID, size, radioactivityLevel, quantityOfMicroframgnets, digitizedScan);
//	controller.assistantAddBot(ID);
//	vector<Bot> vector = controller.assistantGetBots();
//	assert(vector.size() == 1);
//
//	remove(text);
//
//}
//
//void test_setFilename__GoodInput__Returns1()
//{
//	char text[32] = "text.txt", text2[32] = "text2.txt";
//	RepositoryFiles repo = RepositoryFiles(text);
//	RepositoryFiles repoAssistant = RepositoryFiles(text2);
//	Controller controller = Controller(repo, repoAssistant);
//	unsigned result = controller.setFilename("newinput.txt");
//	assert(result == 1);
//}
//
//void testController()
//{
//	std::cout << "\nInfo: currently running tests for controller\n";
//	test_controllerAddBot__GoodInput__Returns1();
//	test_controllerAddBot__BadInput__Returns0();
//	test_controllerRemoveBot__BadInput__Returns0();
//	test_controllerRemoveBot__GoodInput__Returns1();
//	test_controllerUpdateBot__GoodInput__Returns1();
//	test_controllerUpdateBot__BadInput__Returns01();
//	test_controllerUpdateBot__BadInput__Returns02();
//	test_controllerGetAll__NoInput_ReturnsAll();
//	test_assistantAddBot__GoodInput__Returns1();
//	test_nextBot__NoInput__ReturnsNextBot();
//	test_nextBot_nextBot__NoInput__ReturnsFirstBot();
//	test_assistantGetBots__NoInput__ReturnsAllBots();
//	test_setFilename__GoodInput__Returns1();
//	std::cout << "Result: the tests are fine!    :) \n";
//}
//
////
////// these are the tests for the validator :)
////void test_checkID__GoodInput__ReturnsTrue()
////{
////	std::string string = "ASDF";
////	Validator validator = Validator();
////	bool result = validator.checkID(string);
////	assert(result == true);
////}
////
////void test_checkSize__GoodInput__ReturnsTrue()
////{
////	std::string string = "40X30X20";
////	Validator validator = Validator();
////	bool result = validator.checkSize(string);
////	assert(result == true);
////}
////
////void test_checkSize__BadInput__ReturnsFalse()
////{
////	std::string string = "A40X20X30";
////	Validator validator = Validator();
////	bool result = validator.checkSize(string);
////	assert(result == false);
////}
////
////void test_checkRadioactivityLevel__GoodInput__ReturnsTrue()
////{
////	std::string string = "4000";
////	Validator validator = Validator();
////	bool result = validator.checkRadioactivityLevel(string);
////	assert(result == true);
////}
////
////void test_checkRadioactivityLevel__BadInput__ReturnsFalse1()
////{
////	std::string string = "ASDF";
////	Validator validator = Validator();
////	bool result = validator.checkRadioactivityLevel(string);
////	assert(result == false);
////}
////
////void test_checkRadioactivityLevel__BadInput__ReturnsFalse2()
////{
////	std::string string = "400.2.1";
////	Validator validator = Validator();
////	bool result = validator.checkRadioactivityLevel(string);
////	assert(result == false);
////}
////
////void test_checkQuantityOfMicrofragments__GoodInput__ReturnsTrue()
////{
////	double number = 300;
////	Validator validator = Validator();
////	bool result = validator.checkQuantityOfMicrofragments(number);
////	assert(result == true);
////}
////
////
////void test_checkDigitizedScan__GoodInput__ReturnsTrue()
////{
////	std::string string = "ASD21e#";
////	Validator validator = Validator();
////	bool result = validator.checkDigitizedScan(string);
////	assert(result == true);
////}
////
////void testValidator()
////{
////	std::cout << "\nInfo: currently running tests for the validator... \n";
////	test_checkID__GoodInput__ReturnsTrue();
////	test_checkSize__GoodInput__ReturnsTrue();
////	test_checkSize__BadInput__ReturnsFalse();
////	test_checkRadioactivityLevel__GoodInput__ReturnsTrue();
////	test_checkRadioactivityLevel__BadInput__ReturnsFalse1();
////	test_checkRadioactivityLevel__BadInput__ReturnsFalse2();
////	test_checkQuantityOfMicrofragments__GoodInput__ReturnsTrue();
////	test_checkDigitizedScan__GoodInput__ReturnsTrue();
////	std::cout << "Result: the tests are fine!    :)\n";
////}
//
////void testAll()
////{
////	testDomain();
////	testDynamicVector();
////	testRepositoryFiles();
////	testRepositoryMemory();
//////	testValidator();
////	testController();
////
////}
