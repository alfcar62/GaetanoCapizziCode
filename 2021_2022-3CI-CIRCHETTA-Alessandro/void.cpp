//Soluzione Salerno
void gotoxy (int x, int y)
        {
            printf("\033[%d;%dH", y, x);
        }


int main()
{int col=0;
system("cls");
	for (col=0;col<117;col++)
	{
system("cls");
	gotoxy (col,10);
	printf("ciao");
	Sleep(10);
	//getchar();

		}
		for (col=117;col>1;col--)
	{
system("cls");
	gotoxy  (col,10);
	printf("ciao");
	Sleep(10);
	//getchar();
		}
}
