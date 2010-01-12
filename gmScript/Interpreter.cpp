#include "Interpreter.h"
#include "functions/strip.h"
#include "functions/functions.h"
#include <iostream>
#include <sstream>
#include <string>

#ifdef SIMPLEGUI_H
gui*		consoleWindow;
textbox*	consoleText;
button*		consoleButton;
Interpreter interpreter;


void executeConsoleScript()
{
	interpreter.execute(consoleText->getString());
}
#endif 

Interpreter interpreter;

void Merror(const char* message){
	std::cout << message << std::endl;
}

//Interpreter::(*error)(const char*) = Merror;

void Interpreter::init()
{
//consoleWindow = new gui(-1,-1,"");
//consoleButton = new button("Exec!",executeConsoleScript);
//consoleText = new textbox();
//consoleWindow->newElem(consoleText);
//consoleWindow->newElem(consoleButton);
//GUIList.add(consoleWindow);
	debug.error = Merror;
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
		for(const char* temp = &script[i];*temp != ';' && *temp != 0 ;i++,temp++)
		{
		}
		i++;
			if(script[i] == 0 || script[i-1] == 0)
			{
				i = -1;
				return 1;
			}
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
			if(isalnum(c)){
			c = 0;
			break;
			}
			else
				c = script[i];
		}
	}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////....bezig!!...////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//int count = 0;

		if(strip.GMSisFunction(script))
		{	

			/*if(GMSisFunction(ctemp)){
			function* func = 0;
			dataType** args = findFuncArgs(func, ctemp);
			func = findFunction(ctemp,args);
			return func->exec(args);
*/

 			dataType** args = strip.findFuncArgs(&script[strip.results.index2]+1);
			function* temp = strip.findFunction(&script[strip.results.index1],args);
			if(temp != 0)
				temp->exec(args);
			else{
				std::stringstream message;
				std::string name = script;
				message << "[ERROR]unknown function ";
				message.write(script,strip.findCharRetIndex(script,'('));
				message << '(';

			//	if(strip.results.number = 0)
				//	message << getTypeName(args[i]);
				for(int i = 0;i < strip.results.number;i++){
					message << getTypeName(args[i]);
					if(i == strip.results.number-1)
						message << ").";
					else{
						message << ',';
						message << ' ';
					}
				}
				debug.error(message.str().c_str());
			
			}
			return 0;
		}


				int tempif = strip.findCharRetIndex(script, '=');
				if(tempif != -1){
					dataType* temp = findVar(script);
					*temp = *strip.GMSfindVar(&script[tempif],0);
						int* p = new int;
						return 0;
						//*(int*)tempvar +=	*(int*)GMScalculateString(&script[tempif])->var;

						//std::cout << (**it) << std::endl;
						//std::cout << *((int*)addresTable[count]) << std::endl;
						//*it findchar
				}
	debug.error("[ERROR]huh?");
	return 1;
}
