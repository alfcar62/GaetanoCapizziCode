/*
Autore: Bellini Antonio
Data:24/11/2021
Classe: 3C INFORMATICA
Programma che dato un numero in input in cifre, da in output lo stesso numero ma scritto in lettere.
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
	{
	 int m,c,d,u,numero,restoMigliaia,restoCentinaia,restoDecine;
	 do
	  {
	 	printf("Inserisci un numero(deve essere compreso tra 1 e 9999)-->");
	 	scanf("%d",&numero);
   	  }while(numero<1||numero>9999);
	 
	 //Dividiamo il numero dato in input per dividerlo in migliaia, centinaia, decine e unità.
	 	//Divido prima per 1000, cosi ho il numero di migliaia, poi divido però ottenendo solo il resto
	 	m=numero/1000;
	 	restoMigliaia=numero%1000;
	 	//Divido prima per 100, cosi ho il numero di centinaia, poi divido però ottenendo solo il resto
		c=restoMigliaia*100;
	 	restoCentinaia=restoMigliaia%100;
	 	//Divido prima per 10, cosi ho il numero di decine, poi divido però ottenendo solo il resto, ovvero il numero delle unità.
	 	d=restoCentinaia/10;
	 	u=restoCentinaia%10;
	 
	 switch(m)
	 	{
	 	 case(1): { printf("Mille");   	   }break;
		 case(2): { printf("Duemila"); 	   }break;
		 case(3): { printf("Tremila"); 	   }break;
		 case(4): { printf("Quattromila"); }break;
		 case(5): { printf("Cinquemila");  }break;
		 case(6): { printf("Seimila"); 	   }break;
		 case(7): { printf("Settemila");   }break;
		 case(8): { printf("Ottomila");    }break;
		 case(9): { printf("Novemila");    }break;
		}
	
	 switch(c)
		{
	 	 case(1): { printf("cento");    	}break;
	 	 case(2): { printf("duecento"); 	}break;
	 	 case(3): { printf("trecento"); 	}break;
	 	 case(4): { printf("quattrocento");	}break;
	 	 case(5): { printf("cinquecento"); 	}break;
	 	 case(6): { printf("seicento"); 	}break;
	 	 case(7): { printf("settecento");   }break;
	 	 case(8): { printf("ottocento");	}break;
	 	 case(9): { printf("novecento"); 	}break;
		}
	 
	 switch(d)
	 	{	
	 	 case(1):
	 	 	{ switch(u) { case(1): { printf("undici");  	}break;
				 		  case(2): { printf("dodici");  	}break;
				 		  case(3): { printf("tredici"); 	}break;
				 		  case(4): { printf("quattordici"); }break;
				 		  case(5): { printf("quindici"); 	}break;
				 		  case(6): { printf("sedici");	    }break;
				 		  case(7): { printf("diciasette"); 	}break;
				 		  case(8): { printf("diciotto");	}break;
				 		  case(9): { printf("diciannove"); 	}break;						
						}	
			}break;
	 	 case(2): { if(u==2||u==8) 
			  			printf("vent"); 
				  }break;
	 	 case(3): { if(u==1||u==8)
	 	 	 			printf("trent");	
				  }break;
	 	 case(4): { if(u==1||u==8)
	 	 	 			printf("quarant");	
				  }break;
	 	 case(5): { if(u==1||u==8)	
	 	 	 	 		printf("cinquant");	
				  }break;
	 	 case(6): { if(u==1||u==8)	
	 	 				printf("sessant");	
				  }break;
	 	 case(7): { if(u==1||u==8)	
	 	 	 			printf("settant");	
				  }break;
	 	 case(8): { if(u==1||u==8)	
	 	 	 			printf("ottant");	
				  }break;
	 	 case(9): { if(u==1||u==8)	
	 	 	 			printf("novant");	
				  }break;
		}
	 
	 switch(u)
		{ case(1): { if(d!=1)
			   			printf("uno");	
				   }break;
	 	 case(2): { if(d!=1)
			   			printf("due");	
				  }break;
	 	 case(3): { if(d!=1)
			   			printf("tre");	
				  }break;
	 	 case(4): { if(d!=1)
			   			printf("quattro");	
				  }break;
	 	 case(5): { if(d!=1)
			   			printf("cinque");	
				  }break;
	 	 case(6): { if(d!=1)
			  	 		printf("sei");	
				  }break;
	 	 case(7): { if(d!=1)
			   			printf("sette");	
				  }break;
	 	 case(8): { if(d!=1) 			   
		  				printf("otto");	
				  }break;
	 	 case(9): { if(d!=1)
			   			printf("nove");	
				  }break;
		}
	 	
	 return 0;
	}
