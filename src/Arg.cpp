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

void help()//Gestion de l'ouverture et de l'affichage de l'aide
{
	char str;

	FILE * pFile;
	pFile = fopen ("../src/help.txt","r");
	if (pFile!=NULL)
	{
		while(fscanf(pFile, "%c", &str)!=EOF)
		{
			cout << str;
		}

	  fclose (pFile);
	}
	else
		cout << "\n Failed to load Help, pls reinstall the software or contact the support at 0820 456 789" << endl;
}


void Arg::readArg(int nbrArg, char **myArg, int *state, string *newdata)//Gestion des arguments
{
	/*
	cout << "\n nbrArg:" << nbrArg << endl;

	for(int i=0;i<nbrArg;i++)
		cout << "\n myArg:" << myArg[i] << endl;
	 */


	/*Pour ajouter une commande, aller dans le nombre d'agument qui correspond
	 * et ajouter la fonction souhaitée.
	 */

	switch ( nbrArg )
	{
	  case 1://Si pas d'argument
		  cout << "\nNo request mentioned. \nOpenning Software Help...\n" << endl;
		  help();//Ouverture de l'help
		  *state=1;
	  break;

	  case 2://Si Help ou File (sans nom de fichier)
		  if(string(myArg[1])=="--help")
		  {
			  cout << "\nOpenning Software Help\n" << endl;
			  help();//Ouverture de l'help
			  *state=1;
			  break;
		  }
		  else
		  {
			  if(string(myArg[1])=="--file")
			  {
				  cout << "\nError: no file mentioned." << endl;
				  *state=1;
			  }
			  else
			  {
				  cout << "\nError Arg" << endl;
				  *state=1;
			  }

		  }
	  break;

	  case 3://Si overture de fichier
	  		  if(string(myArg[1])=="--file")
	  		  {
	  			  cout << "\nOpenning file" << endl;
	  		  }
	  		  else
			  {
				  cout << "\nError Arg" << endl;
				  *state=1;
			  }
	  break;

	  case 13://Si ajout de ligne dans csv
		  if((string(myArg[1])=="--name")&&(string(myArg[3])=="--phone")&&(string(myArg[5])=="--expense")&&(string(myArg[7])=="--group")&&(string(myArg[9])=="--type")&&(string(myArg[11])=="--file"))
		  {
			  cout << "\nCreation Nouvelle ligne" << endl;
			  *newdata=string(myArg[2])+','+string(myArg[4])+','+string(myArg[6])+','+string(myArg[8])+','+string(myArg[10]);
			  //cout << *newdata << endl;
		  }
		  else
		  {
			  cout << "\nError: options --name, --phone, --expense, --group and --type must be strictly used together." << endl;
			  *state=1;
		  }
	  break;

	  default://Defaut
		  if((string(myArg[1])=="--name")||(string(myArg[1])=="--phone")||(string(myArg[1])=="--expense")||(string(myArg[1])=="--group")||(string(myArg[1])=="--type"))
		  {
			  cout << "\nError: options --name, --phone, --expense, --group and --type must be strictly used together." << endl;
			  *state=1;
		  }
		  else
		  {
			  cout<<"\nError Arg"<< endl;
			  *state=1;
		  }
	    break;
	  }

}
