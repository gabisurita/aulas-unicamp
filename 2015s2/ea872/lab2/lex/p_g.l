%{
char *unidades[]={"primeiro","um","dois","tres","quatro","cinco",
               "seis", "sete","oito","nove"};
char *interm[]={"dez","onze","doze","treze",
                 "quatorze","quinze","dezesseis",
                 "dezessete","dezoito","dezenove"};
char *dezenas[]={"vinte","trinta","quarenta","cinquenta",
                 "sessenta","setenta","oitenta","noventa"};
char *meses[]={"janeiro","fevereiro","marco","abril","maio",
               "junho","julho","agosto","setembro",
               "outubro","novembro","dezembro"};
%}
%START Date
FirstField  [ ]..[/]
SecondField [/*]..[/*]
ThirdField  [/]..[ ]

%%

{FirstField}    {Dia();};
{SecondField}   {Mes();};
{ThirdField}    {Ano();};

%%
Dia(){ 
  //
}
Mes(){ 
  //
}
Ano(){ 
  //
}




//FirstField  [ ]..[/]
//SecondField [/]..[/]
//ThirdField  [/]..[ ]
