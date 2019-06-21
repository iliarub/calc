#include "func.h"
plug* init(char p[], char b[], char f[])
{
	plug* plg;
	plg = (plug*)malloc(sizeof(plug));
	strcpy(plg->nameplug, p);
	strcpy(plg->namebib, b);
	strcpy(plg->namefunc, f);

	plg->next = NULL;
	return(plg);

}
plug* add(plug* plg)
{
	char p[15], b[15], f[15];
	getchar();
	printf("Vvedite nazvanie plugina \n");
	fgets(p, sizeof p, stdin);
	printf("Vvedite nazvanie biblioteki \n");
	fgets(b, 15, stdin);
	printf("Vvedite nazvanie funckcii \n");
	fgets(f, 15, stdin);

	if (plg == NULL) return(init(p, b, f));
	plug* tmp;
	tmp = (plug*)malloc(sizeof(plug));

	while (plg->next != NULL)
	{
		plg = plg->next;
	}
	plg->next = tmp;
	strcpy(tmp->nameplug, p);
	strcpy(tmp->namebib, b);
	strcpy(tmp->namefunc, f);
	tmp->next = NULL;
	return(tmp);
}

plug *del(plug *dd, plug *root)
{
		plug *tmp;
		tmp = root;
		int i = 0;
		while (tmp->next != dd)
		{
				tmp = tmp->next;
				i++;
		}
		tmp->next = dd->next;
		free(dd);
		return(tmp);

}

void print(plug* plg)
{
	printf("vashi fubckciu\n");
	plug* tmp;
	tmp = plg;

	for(int i=1; tmp != NULL; i++)
	{
		printf("%d) ", i);
		printf("%s \n", tmp->nameplug);
		tmp = tmp->next;
	}
}

plug* search(int i, plug *plg)
{		plug *tmp;
		tmp = plg;
	i--;
	while (i!=0)
	{
		if (tmp == NULL) { printf("Pusto"); return (NULL); }
		plg = plg->next;
		i--;
	}
	return(tmp);
}

void use(plug* plg)
{
	if (plg != 0)
	{
		cc cc3;
		void* dl;
		char lib[20]="plag/";
			strcat(lib, plg->namebib);
		dl = dlopen((const char*)lib, RTLD_NOW);
		if (!dl) { printf("no open\n"); }
		else
		{
			cc(*tempf)();
			tempf = dlsym(dl, (const char*)plg->namefunc);
			cc3 = tempf();
			printf("%f + %fi\n", cc3.d, cc3.m);
			dlclose(dl);
		}
	}

}

void menu()
{


	plug* b = NULL;


	int t = 5;
	while (t) {
		printf("vibirite deistvie: \n 1-add plug \n 2-del \n 3-use \n 0-exit\n");
		scanf("%d", &t);
		switch (t)
		{
		case 1: {
			if (b == NULL) {
				b = add(b);
			}
			else
				add(b);
			break;  }
		case 2:
		{
			print(b);
			printf("vvedite znachenie elem na udalenie\n");
			int t2 = 1;

			scanf("%d", &t2);
			if (search(t2, b))
				del(search(t2, b), b);
			else printf("net elementa\n");
			break;

		}
		case 3: {

			int i;
			printf("viberete plagin\n");
			print(b);
			scanf("%d", &i);
			use(search(i, b));
			break;

		}
		default:
			break;
		}
	}

}




















/*list *del(list *dd, list *root)
{
	list *tmp;
	tmp = root;
	int i = 0;
	while (tmp->next != dd)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = dd->next;
	free(dd);
	return(tmp);

}*/

