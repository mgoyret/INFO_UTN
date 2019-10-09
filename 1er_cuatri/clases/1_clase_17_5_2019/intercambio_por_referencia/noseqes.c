void funcionintercambio(int *p, int *q)
{
	int aux;

	aux = *p;
	*p = *q;
	*q = aux;
}
