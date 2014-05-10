/*
 * Arg.cpp
 *
 *  Created on: 6 mai 2014
 *      Author: paul
 */

#include "Arg.hpp"

Arg::Arg()
{
}

Arg::~Arg()
{
}

void help()
{
	cout << "\n BLABLABLA" << endl;
}

int Arg::readArg(int nbrArg, char **myArg, int *state)
{
	/*
	cout << "\n nbrArg:" << nbrArg << endl;

	for(int i=0;i<nbrArg;i++)
		cout << "\n myArg:" << myArg[i] << endl;
	 */

	switch ( nbrArg )
	{
	  case 1:
		  cout << "\nNo request mentioned. \nOpenning Software Help..." << endl;
		  help();
		  *state=1;
	  break;

	  case 2:
		  if(string(myArg[1])=="--help")
		  {
			  cout << "\nOpenning Software Help" << endl;
			  help();
			  *state=1;
			  break;
		  }
		  if(string(myArg[1])=="--file")
		  {
			  cout << "\nError: no file mentioned." << endl;
			  *state=1;
		  }
	  break;

	  case 3:
	  		  if(string(myArg[1])=="--file")
	  		  {
	  			  cout << "\nOpenning file" << endl;
	  		  }
	  break;

	  case 13:
		  if((string(myArg[1])=="--name")&&(string(myArg[3])=="--phone")&&(string(myArg[5])=="--expense")&&(string(myArg[7])=="--group")&&(string(myArg[9])=="--donor")&&(string(myArg[11])=="--file"))
		  {
			  cout << "\nCreation Nouvelle ligne" << endl;
		  }
	  break;

	  default:
	    cout<<"\nError: no file mentioned."<< endl;
		*state=1;
	    break;
	  }

/*	if(myArg[1] == NULL)
	{
		cout << "\nNo input file specified... " << endl;
	    *state=1;
	}*/

}
