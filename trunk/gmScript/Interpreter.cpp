#include "Interpreter.h"
#include "functions/strip.h"
#include "functions/functions.h"
#include <iostream>

gui*		consoleWindow;
textbox*	consoleText;
button*		consoleButton;
Interpreter interpreter;

void Interpreter::init()
{
consoleWindow = new gui(-1,-1,"");
consoleButton = new button("Exec!",executeConsoleScript);
consoleText = new textbox();
consoleWindow->newElem(consoleText);
consoleWindow->newElem(consoleButton);
GUIList.add(consoleWindow);
}

int Interpreter::execute(const char* script)
{
	char* tempScript = new char[1000];// tijdelijke opllosing, weet niet hovel chars er in moet.
	strcpy(tempScript, script);
	//char tChar = script[0];
	std::cout << "inside exec\n";
	for(int i = 0;;)
	{
		handleVar(&tempScript[i]);
		for(const char* temp = &script[i];*temp != ';';i++,temp++)
		{
			if(*temp == '\0')
			{
				i = -1;
				return 1;
			}
		}
		i++;
	}
return 1;
}

bool Interpreter::handleVar(const char* script)
{
	if(strncmp(script, "int",3) == 0)
	{	
		//is het een functie?
		/////////////////////////////////////////////
		//
		//is het een initialisatie?
		//
		int index;
		char temp = script[3];
		for(index = 0;!isalpha(script[index+3]);index++)
		{
			temp = script[index];
		}
		int index2;
		for(index2 = index;script[index2 + 3] != ';';index2++){}
		//script[index2 + 3] = '\0';
		static_cast<char>(script[index2+3]) = 0;
	//	script[index+3] = '\0';
	
		char *toList;
		toList = new char[index2];
		strcpy(toList,&script[4]);
		variables.push_back(new dataType(new int,toList));
		//addresTable.push_back(new int);
		//stringTable.push_back(toList);
		std::cout << &script[4] << std::endl;
	}
	//als het geen een van de opties boven is dan
	// willen we iets veranderen, denk ik.
	else{
		int i = 0;char c = 0;
		for(;;i++)
		{
			if(isalpha(c)){
			c = 0;
			break;
			}
			else
				c = script[i];
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////....bezig!!...////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//int count = 0;

		if(strip.GMSisFunction(script))
		{	
			function* temp = strip.findFunction(&script[strip.results.index1]);
			if(temp != 0){
				dataType* a;
				temp->exec(strip.findFuncArgs(&script[strip.results.index2]));
			}
		}


				int tempif = strip.findCharRetIndex(script, '=');
				if(tempif != -1){
				dataType temp = findVar(script);
						int* p = new int;
			
						temp =	GMScalculateString(&script[tempif]);

						//std::cout << (**it) << std::endl;
						//std::cout << *((int*)addresTable[count]) << std::endl;
						//*it findchar
				}
	}
	return 1;
}

void executeConsoleScript()
{
	interpreter.execute(consoleText->getString());
}