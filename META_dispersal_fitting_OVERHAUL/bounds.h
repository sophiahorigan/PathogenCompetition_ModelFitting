double bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

if (i==2)		{	low = -4.0;			high = -0.5;	}		//nuV	(log10)
else if (i==3)	{	low = -7.50;			high = -3.50;	}		//nuF