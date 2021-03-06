/** funciones.cpp */
#include <iostream>
#include <vector>
#include "main.h"
using namespace std;

/** Suma los elementos del arreglo b y
 *  devuelve el resultado.
 */
uint selem(unsigned int b[NELEM(bucket)],int s)
{
  int i,suma=0;//,x,z;
  for(i=0; i<=(int)NELEM(bucket); i++)
  {
	 suma=suma+b[i];
  }
  return suma;
}/*end selem()*/

/**Stub (inicialmente 2020.03.10)
 * Debe colocar en el vector string_vec las subsecuencias de
 * characters del string linea que no contienen characters ' '.
  pre:string_vec.size()=0
*/
void fill_string_vec(string linea,
					 vector<string>& string_vec)
{
  uint i,inic=-1,fin;
  std::string str_tmp;
  /**detect if string is fill of ' 's*/
  for(i=0;i<linea.size();i++)
  {
	if(linea[i]==' ')
		continue;
	inic=i;
	break;
  }
  if(inic<0)
	goto out;
  while(i<=linea.size()-1)
  {
	for(i=inic;i<linea.size();i++)
	{
	  if(linea[i]==' ')
		continue;
	  inic=i;
	  break;
	}
	for(i=inic;i<linea.size();i++)
	{
	  if((' '==linea[i])||('\0'==linea[i])||(i==(linea.size()-1))){
		 fin=i;
		 str_tmp=linea.substr(inic,fin-inic+1);

		 //print_index_char_of_string(str_tmp);
		 if(str_tmp.size()>=2){
		 /**Quitar coma --si la hay--*/
		 if(str_tmp[str_tmp.size()-2]==',')
			str_tmp=str_tmp.substr(0,str_tmp.size()-2);
		 /**Quitar punto y coma --si lo hay--*/
		 if(str_tmp[str_tmp.size()-2]==';')
			str_tmp=str_tmp.substr(0,str_tmp.size()-2);
		 /**Quitar punto --si lo hay--*/
		 if(str_tmp[str_tmp.size()-2]=='.')
			str_tmp=str_tmp.substr(0,str_tmp.size()-2);
		 }
		 if(!is_included(str_tmp,string_vec))
		   string_vec.push_back(str_tmp);
		 inic=fin+1;
		 break;
	   }
	 }/*end for()*/
  }/*end while()*/

out:
	return;
}/*end fill_string_vec()*/

void print_vector_string(vector<std::string> v)
{
	unsigned int i;
	for(i=0;i<v.size();i++)
	{
#ifndef CPPBUILDER
		cout<<v[i]<<"\n";
#else
		printf("%s\n",&(v[i][0]));
#endif /*CPPBUILDER*/
    }
}/*end print_vector_string()*/

bool is_included(std::string word,vector<string> word_list)
{
  for(uint i=0;i<word_list.size();i++)
  {
#ifndef CPPBUILDER
	if(word==word_list[i])
#else
    if(strcmp(&word[0],&(word_list[i][0])))
#endif /*CPPBUILDER*/
      return true;
  }
  return false;
}/*end is_included()*/

void print_index_char_of_string(string s)
{
  cout<<"(* s.size()="<<s.size()<<"\n";
  for(uint i=0;i<s.size();i++)
  {
    printf("%2d %c\n",i,s[i]);
  } 
  cout<<"*)\n";
}/*end print_index_char_of_string()*/

uint mapa(string word,StringYuint * syu_pt,uint size)
{
  for(uint i=0;i<size;i++)
  {
//cout<<"mapa() -->syu_pt[i].palabra="<<syu_pt[i].palabra<<"\n";
#ifndef CPPBUILDER
	if(word==syu_pt[i].palabra)
#else
    if(strcmp(&word[0],&(syu_pt[i].palabra[0])))
#endif /*CPPBUILDER*/
      return syu_pt[i].I;   /*a positive integer (by construction)*/
  }
  return 0;
}

uint StringYuint::count=0;

StringYuint::StringYuint(string p):palabra(p)
{
  count++;
  I=count;
}

bool is_space(char c)
{
  return (' '==c);
}


