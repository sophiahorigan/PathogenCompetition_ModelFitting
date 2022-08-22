double ls_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//metapopulation one
if (i==0)			{	low = 0;			high = 100;		}	//initS fungus-only
else if (i==1)		{	low = 70;			high = 140;		}	//initS virus-only
else if (i==2)		{	low = 70;			high = 140;		}	//initS fungus-virus
else if (i==3)		{	low = 70;			high = 140;		}	//initS control

else if (i==4)		{	low = 0;			high = 0.01;	}	//initV fungus-only
else if (i==5)		{	low = 0;			high = 0.2;		}	//initV virus-only
else if (i==6)		{	low = 0;			high = 0.2;		}	//initV fungus-virus
else if (i==7)		{	low = 0;			high = 0.01;	}	//initV control

else if (i==8)		{	low = 0;			high = 0.01;	}	//initR fungus-only
else if (i==9)		{	low = 0;			high = 0.01;	}	//initR virus-only
else if (i==10)		{	low = 0;			high = 0.01;	}	//initR fungus-virus
else if (i==11)		{	low = 0;			high = 0.01;	}	//initR control

//metapopulation two
else if (i==12)		{	low = 70;			high = 140;		}	//initS fungus-only
else if (i==13)		{	low = 70;			high = 140;		}	//initS virus-only
else if (i==14)		{	low = 70;			high = 140;		}	//initS fungus-virus
else if (i==15)		{	low = 70;			high = 140;		}	//initS control

else if (i==16)		{	low = 0;			high = 0.01;	}	//initV fungus-only
else if (i==17)		{	low = 0;			high = 0.2;		}	//initV virus-only
else if (i==18)		{	low = 0;			high = 0.2;		}	//initV fungus-virus
else if (i==19)		{	low = 0;			high = 0.01;	}	//initV control

else if (i==20)		{	low = 0;			high = 0.01;	}	//initR fungus-only
else if (i==21)		{	low = 0;			high = 0.01;	}	//initR virus-only
else if (i==22)		{	low = 0;			high = 0.01;	}	//initR fungus-virus
else if (i==23)		{	low = 0;			high = 0.01;	}	//initR control

//metapopulation three
else if (i==24)		{	low = 70;			high = 140;		}	//initS fungus-only
else if (i==25)		{	low = 70;			high = 140;		}	//initS virus-only
else if (i==26)		{	low = 70;			high = 140;		}	//initS fungus-virus
else if (i==27)		{	low = 70;			high = 140;		}	//initS control

else if (i==28)		{	low = 0;			high = 0.01;	}	//initV fungus-only
else if (i==29)		{	low = 0;			high = 0.2;		}	//initV virus-only
else if (i==30)		{	low = 0;			high = 0.2;		}	//initV fungus-virus
else if (i==31)		{	low = 0;			high = 0.01;	}	//initV control

else if (i==32)		{	low = 0;			high = 0.01;	}	//initR fungus-only
else if (i==33)		{	low = 0;			high = 0.01;	}	//initR virus-only
else if (i==34)		{	low = 0;			high = 0.01;	}	//initR fungus-virus
else if (i==35)		{	low = 0;			high = 0.01;	}	//initR control

//metapopulation four
else if (i==36)		{	low = 1;			high = 200;		} 	//initS
else if (i==37)		{	low = 0;			high = 0.5;		} 	//initV
else if (i==38)		{	low = 0;			high = 0.01;	} 	//initR

//metapopulation five
else if (i==39)		{	low = 1;			high = 200;		} 	//initS
else if (i==40)		{	low = 0;			high = 0.5;		} 	//initV
else if (i==41)		{	low = 0;			high = 0.01;	} 	//initR

//metapopulation six
else if (i==42)		{	low = 1;			high = 200;		} 	//initS
else if (i==43)		{	low = 0;			high = 0.5;		} 	//initV
else if (i==44)		{	low = 0;			high = 0.01;	} 	//initR

//dispersal
else if (i==45)		{	low = 0;			high = 100;		} 	//con_mgr //rate of conidia dispersal
else if (i==46)		{	low = 0;			high = 1;		}	//a //distance dispersal parameter conidia
else if (i==47)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==48)		{	low = 0;			high = 0.1;		} 	//a2 //distance dispersal parameter larvae

//coifection
else if (i==49) 	{	low = 0;			high = 1;		}	//coinf_V //coinfecteds produce what proportion of OBs/conidia
else if (i==50) 	{	low = 0;			high = 500;		}	//VFSus //enhanced susceptibility 

//stochasticity
else if (i==51)		{	low = 0;			high = 4;		}	//Rsd_exp
else if (i==52)		{	low = 0;			high = 4;		}	//Fsd_exp
else if (i==53)		{	low = 0;			high = 4;		}	//Rsd_obs
else if (i==54)		{	low = 0;			high = 4;		}	//Fsd_obs

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}
}
// ------------------------------------------------------------------------------------ //
double step(int i)				// bounds on parameters for parhood line search
{
double step_size;

//metapopulation one
if (i==0)			{	step_size = 1;	}	//initS fungus-only
else if (i==1)		{	step_size = 1;	}	//initS virus-only
else if (i==2)		{	step_size = 1;	}	//initS fungus-virus
else if (i==3)		{	step_size = 1;	}	//initS control

else if (i==4)		{	step_size = 0.001;	}	//initV fungus-only
else if (i==5)		{	step_size = 0.005;	}	//initV virus-only
else if (i==6)		{	step_size = 0.005;	}	//initV fungus-virus
else if (i==7)		{	step_size = 0.001;	}	//initV control

else if (i==8)		{	step_size = 0.0005;	}	//initR fungus-only
else if (i==9)		{	step_size = 0.0005;	}	//initR virus-only
else if (i==10)		{	step_size = 0.0005;	}	//initR fungus-virus
else if (i==11)		{	step_size = 0.0005;	}	//initR control

//metapopulation two
else if (i==12)		{	step_size = 1;	}	//initS fungus-only
else if (i==13)		{	step_size = 1;	}	//initS virus-only
else if (i==14)		{	step_size = 1;	}	//initS fungus-virus
else if (i==15)		{	step_size = 1;	}	//initS control

else if (i==16)		{	step_size = 0.001;	}	//initV fungus-only
else if (i==17)		{	step_size = 0.005;	}	//initV virus-only
else if (i==18)		{	step_size = 0.005;	}	//initV fungus-virus
else if (i==19)		{	step_size = 0.001;	}	//initV control

else if (i==20)		{	step_size = 0.0005;	}	//initR fungus-only
else if (i==21)		{	step_size = 0.0005;	}	//initR virus-only
else if (i==22)		{	step_size = 0.0005;	}	//initR fungus-virus
else if (i==23)		{	step_size = 0.0005;	}	//initR control

//metapopulation three
else if (i==24)		{	step_size = 1;	}	//initS fungus-only
else if (i==25)		{	step_size = 1;	}	//initS virus-only
else if (i==26)		{	step_size = 1;	}	//initS fungus-virus
else if (i==27)		{	step_size = 1;	}	//initS control

else if (i==28)		{	step_size = 0.001;	}	//initV fungus-only
else if (i==29)		{	step_size = 0.005;	}	//initV virus-only
else if (i==30)		{	step_size = 0.005;	}	//initV fungus-virus
else if (i==31)		{	step_size = 0.001;	}	//initV control

else if (i==32)		{	step_size = 0.0005;	}	//initR fungus-only
else if (i==33)		{	step_size = 0.0005;	}	//initR virus-only
else if (i==34)		{	step_size = 0.0005;	}	//initR fungus-virus
else if (i==35)		{	step_size = 0.0005;	}	//initR control

//metapopulation four
else if (i==36)		{	step_size = 5;	}	//initS
else if (i==37)		{	step_size = 0.05;	}	//initV
else if (i==38)		{	step_size = 0.0005;	} 	//initR

//metapopulation five
else if (i==39)		{	step_size = 5;	}	//initS
else if (i==40)		{	step_size = 0.05;	} 	//initV
else if (i==41)		{	step_size = 0.0005;	} 	//initR

//metapopulation six
else if (i==42)		{	step_size = 5;	}	//initS
else if (i==43)		{	step_size = 0.05;	}  	//initV
else if (i==44)		{	step_size = 0.0005;	}	//initR

//dispersal
else if (i==45)		{	step_size = 1;	}  	//con_mgr //rate of conidia dispersal
else if (i==46)		{	step_size = .01;	} 	//a //distance dispersal parameter
else if (i==47)		{	step_size = 1;	}	//lar_mgr //prob of dispersal
else if (i==48)		{	step_size = .0001;	}	//a2 //prob of dispersal

//coifection
else if (i==49) 	{	step_size = .01;	}	//coinf_V //coinfecteds produce what proportion of OBs/conidia
else if (i==50) 	{	step_size = 5;	}	//VFSus //enhanced susceptibility 

//stochasticity
else if (1==51)		{	step_size = .05;	}	//Rsd_exp
else if (1==52)		{	step_size = .05;	}	//Fsd_exp
else if (1==53)		{	step_size = .05;	}	//Rsd_obs
else if (1==54)		{	step_size = .05;	}	//Fsd_obs

return step_size;
}
// ------------------------------------------------------------------------------------ //
double prior_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//metapopulation one
if (i==0)			{	low = 0;			high = 5000;	}	//initS fungus-only
else if (i==1)		{	low = 0;			high = 5000;	}	//initS virus-only
else if (i==2)		{	low = 0;			high = 5000;	}	//initS fungus-virus
else if (i==3)		{	low = 0;			high = 5000;	}	//initS control

else if (i==4)		{	low = 0;			high = 1;		}	//initV fungus-only
else if (i==5)		{	low = 0;			high = 1;		}	//initV virus-only
else if (i==6)		{	low = 0;			high = 1;		}	//initV fungus-virus
else if (i==7)		{	low = 0;			high = 1;		}	//initV control

else if (i==8)		{	low = 0;			high = 1;		}	//initR fungus-only
else if (i==9)		{	low = 0;			high = 1;		}	//initR virus-only
else if (i==10)		{	low = 0;			high = 1;		}	//initR fungus-virus
else if (i==11)		{	low = 0;			high = 1;		}	//initR control

//metapopulation two
else if (i==12)		{	low = 0;			high = 5000;	}	//initS fungus-only
else if (i==13)		{	low = 0;			high = 5000;	}	//initS virus-only
else if (i==14)		{	low = 0;			high = 5000;	}	//initS fungus-virus
else if (i==15)		{	low = 0;			high = 5000;	}	//initS control

else if (i==16)		{	low = 0;			high = 1;		}	//initV fungus-only
else if (i==17)		{	low = 0;			high = 1;		}	//initV virus-only
else if (i==18)		{	low = 0;			high = 1;		}	//initV fungus-virus
else if (i==19)		{	low = 0;			high = 1;		}	//initV control

else if (i==20)		{	low = 0;			high = 1;		}	//initR fungus-only
else if (i==21)		{	low = 0;			high = 1;		}	//initR virus-only
else if (i==22)		{	low = 0;			high = 1;		}	//initR fungus-virus
else if (i==23)		{	low = 0;			high = 1;		}	//initR control

//metapopulation three
else if (i==24)		{	low = 0;			high = 5000;	}	//initS fungus-only
else if (i==25)		{	low = 0;			high = 5000;	}	//initS virus-only
else if (i==26)		{	low = 0;			high = 5000;	}	//initS fungus-virus
else if (i==27)		{	low = 0;			high = 5000;	}	//initS control

else if (i==28)		{	low = 0;			high = 1;		}	//initV fungus-only
else if (i==29)		{	low = 0;			high = 1;		}	//initV virus-only
else if (i==30)		{	low = 0;			high = 1;		}	//initV fungus-virus
else if (i==31)		{	low = 0;			high = 1;		}	//initV control

else if (i==32)		{	low = 0;			high = 1;		}	//initR fungus-only
else if (i==33)		{	low = 0;			high = 1;		}	//initR virus-only
else if (i==34)		{	low = 0;			high = 1;		}	//initR fungus-virus
else if (i==35)		{	low = 0;			high = 1;		}	//initR control

//metapopulation four
else if (i==36)		{	low = 0;			high = 5000;	} 	//initS
else if (i==37)		{	low = 0;			high = 1;		} 	//initV
else if (i==38)		{	low = 0;			high = 1;		} 	//initR

//metapopulation five
else if (i==39)		{	low = 0;			high = 5000;	}	//initS
else if (i==40)		{	low = 0;			high = 1;		} 	//initV
else if (i==41)		{	low = 0;			high = 1;		} 	//initR

//metapopulation six
else if (i==42)		{	low = 0;			high = 5000;	} 	//initS
else if (i==43)		{	low = 0;			high = 1;		} 	//initV
else if (i==44)		{	low = 0;			high = 1;		} 	//initR

//dispersal
else if (i==45)		{	low = 0;			high = 10000;	} 	//con_mgr //rate of conidia dispersal
else if (i==46)		{	low = 0;			high = 1;		}	//a //distance dispersal parameter conidia
else if (i==47)		{	low = 0;			high = 10000;	}	//lar_mgr //prob of dispersal
else if (i==48)		{	low = 0;			high = 1;		}	//a2 //distance dispersal parameter larvae


//coifection
else if (i==49) 	{	low = 0;			high = 1;		}	//coinf_V //coinfecteds produce what proportion of OBs/conidia
else if (i==50) 	{	low = 0;			high = 10000;	}	//VFSus //enhanced susceptibility 

//stochasticity
else if (i==51)		{	low = 0;			high = 10;		}	//Rsd_exp
else if (i==52)		{	low = 0;			high = 10;		}	//Fsd_exp
else if (i==53)		{	low = 0;			high = 10;		}	//Rsd_obs
else if (i==54)		{	low = 0;			high = 10;		}	//Fsd_obs

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PRIORS!!\n");	return 0;	}
}

//-----------------------------------------------------------------------------------------------//



double patch_bound(int i,int j)			// bounds on S(0) and R(0) for parhood line search
{
double Slow;	double Shigh;	double Rlow;	double Rhigh;
double eps=-4.0;
double eps2=1.1;
// i=zero isnt used normally
if      (i==0)  {Slow = eps2;                Shigh = 2.1;					Rlow = eps;     Rhigh = .51;	}

else if (i==1)	{Slow = eps2;				Shigh = 10.1;					Rlow = -4.00;		Rhigh = -0.30;	}
else if (i==2)	{Slow = eps2;				Shigh = 10.1;					Rlow = -4.50;		Rhigh = -1.00;	}
else if (i==3)	{Slow = eps2;				Shigh = 10.1;					Rlow = -4.50;		Rhigh = -1.10;	}
else if (i==4)	{Slow = eps2;				Shigh = 10.1;					Rlow = -4.0;		Rhigh = -1.0;	}
else if (i==5)	{Slow = eps2;				Shigh = 10.1;					Rlow = -4.50;		Rhigh = -1.50;	}
else if (i==6)	{Slow = eps2;				Shigh = 10.1;					Rlow = -5.0;		Rhigh = -1.50;	}
else if (i==7)	{Slow = eps2;				Shigh = 10.1;					Rlow = -12.0;		Rhigh = -9.0;	}
else if (i==8)	{Slow = 0.5;				Shigh = 4.0;					Rlow = -12.0;		Rhigh = -9.0;	}

else if (i==9)	{Slow = 1.5;				Shigh = 4.0;					Rlow = eps;		Rhigh = 0.07;	}
else if (i==10)	{Slow = 1.0;				Shigh = 4.0;					Rlow = eps;		Rhigh = 0.03;	}
else if (i==11)	{Slow = 1.0;				Shigh = 4.0;					Rlow = eps;		Rhigh = 0.09;	}
else if (i==12)	{Slow = 1.0;				Shigh = 4.0;					Rlow = eps;		Rhigh = 0.08;	}
else if (i==13)	{Slow = 1.2;				Shigh = 4.0;					Rlow = eps;		Rhigh = 0.08;	}
else if (i==14)	{Slow = 1.5;				Shigh = 4.0;					Rlow = 0.0;		Rhigh = 1.0;	}
else if (i==15)	{Slow = 1.3;				Shigh = 4.0;					Rlow = 0.0;		Rhigh = 1.0;	}
else if (i==16)	{Slow = 1.3;				Shigh = 4.0;					Rlow = 0.0;		Rhigh = 1.0;	}

else			{Slow = 0;				Shigh = 0;				Rlow = 0;		Rhigh = 0;	}

if		(j==1)	return Slow;
else if (j==2)	return Shigh;
else if (j==3)	return Rlow;
else if (j==4)	return Rhigh;
else { printf("PROBLEM WITH BOUNDS ON S(0) or R(0)!!\n");	return 0;	}
}
// --------------------------------------------------------------------------------------- //
double prop_dist(int i,int j)
{
double ulow=0, uhigh=0;
double mean=0, sdev=0;
double Slow=0, Shigh=0;
double Rmean=0,Rsdev=0;

//ulow=0;	uhigh=0;	mean=0;	sdev=0;	Slow=0;	Shigh=0; Rmean=0; Rsdev=0;

if (i==2)		{	ulow =.001;	uhigh=.3;	}
else if (i==4)	{	mean=.13;	sdev =.4;	}
else if (i==5)	{	ulow=.1;	uhigh=1;	}
else if (i==6)	{	ulow=.1;	uhigh=11;	}
else if (i==8)	{	ulow=15;	uhigh=40;	}
else if (i==9)	{	ulow=15;	uhigh=40;	}
else if (i==10)	{	mean=.01;	sdev =.8;	}
else if (i==14)	{	mean=2.6;	sdev =.1;	}
else if (i==15)	{	ulow=1;		uhigh=14;	}
else if (i==16)	{	ulow=0;		uhigh=10;	}

else if ((i>20 && i<=30+DATA_SETS) || (i>50 && i<=50+DATA_SETS))	{
	if (i==21||i==51)		{ Slow=100;		Shigh=6000;	Rmean=20;	Rsdev=.4;	}
	else if (i==22||i==52)	{ Slow=200;		Shigh=1500;	Rmean=20;	Rsdev=.4;	}
	else if (i==23||i==53)	{ Slow=20;		Shigh=700;	Rmean=0;	Rsdev=0;	}
	else if (i==24||i==54)	{ Slow=100;		Shigh=5000;	Rmean=.08;	Rsdev=.4;	}
	else if (i==25||i==55)	{ Slow=10;		Shigh=800;	Rmean=.04;	Rsdev=.3;	}
	else if (i==26||i==56)	{ Slow=10;		Shigh=1500;	Rmean=.05;	Rsdev=.3;	}
	else if (i==27||i==57)	{ Slow=10;		Shigh=1400;	Rmean=.02;	Rsdev=.4;	}
	else if (i==28||i==58)	{ Slow=100;		Shigh=9000;	Rmean=.02;	Rsdev=.4;	}
	else if (i==29||i==59)	{ Slow=100;		Shigh=9000;	Rmean=.03;	Rsdev=.35;	}
	else if (i==30||i==60)	{ Slow=100;		Shigh=2000;	Rmean=.015;	Rsdev=.4;	}
	else if (i==31||i==61)	{ Slow=100;		Shigh=2000;	Rmean=.06;	Rsdev=.5;	}
	else if (i==32||i==62)	{ Slow=100;		Shigh=5000;	Rmean=.05;	Rsdev=.4;	}
	else if (i==33||i==63)	{ Slow=100;		Shigh=1200;	Rmean=.05;	Rsdev=.4;	}
	else if (i==34||i==64)	{ Slow=10;		Shigh=2000;	Rmean=0;	Rsdev=0;	}
	else if (i==35||i==65)	{ Slow=100;		Shigh=5000;	Rmean=0;	Rsdev=0;	}
	else if (i==36||i==66)	{ Slow=100;		Shigh=7000;	Rmean=0;	Rsdev=0;	}

	else {		printf("called index that is not a data-set!!\n");}
}
else	{
	printf("CALLED PROPOSAL DISTRIBUTION FOR NON-EXISTING PARAMETER!!\n");
}

if		(j==1)	return ulow;
else if (j==2)	return uhigh;
else if	(j==3)	return mean;
else if	(j==4)	return sdev;
else if (j==5)	return Slow;
else if (j==6)	return Shigh;
else if (j==7)	return Rmean;
else if (j==8)	return Rsdev;
else {printf("PROBLEM WITH MEAN or SDEV in GAUSSIAN PARAMETERES!!\n");	return 0;	}
}

double r_end(int i)
{
double r_day=31+20;
//r_day=32+30+55;
double end_day;

//Lat and long for all 6 sites in current order (KF, RC1, UM1, RC2, RC3, CCR)
//42.363523, -85.348499
//44.463390, -84.604086
//45.483875, -84.680951
//44.465764, -84.595857
//44.465764, -84.595857
//45.188782, -84.22861

if      (i==0)      end_day = 0;
else if (i==1)		end_day = 20;
else if (i==2)		end_day = 14;
else if (i==3)		end_day = 14;
else if (i==4)		end_day = 12;
else if (i==5)		end_day = 7;
else if (i==6)		end_day = 9;
else if (i==7)		end_day = 17;
else if (i==8)		end_day = 11;
else if (i==9)		end_day = 4;
else if (i==10)		end_day = 5;
else if (i==11)		end_day = 4;
else if (i==12)		end_day = 10;
else if (i==13)		end_day = 25;
else if (i==14)		end_day = 12;
else if (i==15)		end_day = 12;
else if (i==16)		end_day = 12;
//R_end[17]=R_final-21;	R_end[18]=R_final-21;	R_end[19]=R_final-21;

else {
	printf("ERROR IN R END DATE!!!!\n");
	return 0;
}
return (r_day - end_day);
}


double fixed_parm(int i)
{
double value;

if (i==2)			value = 0.0001;			//nuV
else if (i==3)		value = 0.0001;			//nuF
else if (i==4)		value = 0.1;			//k
else if (i==5)		value = 0.2;			//muV
else if (i==6)		value = 0.3;			//muF
else if (i==7)		value = 5.01;		//CK//  beta = the size of accumulated rainfall window
else if (i==8)		value = 5;				//gam_stepsV
else if (i==9)		value = 5;				//gam_stepsF
else if (i==10)		value = 0.03;			//ratio
else if (i==11)		value = 0;				//sdv
else if (i==12)		value = 0;				//sdf
else if (i==13)		value=1.1;			//CK// theta = delay for when to start accumulating rainfall
else if (i==14)		value = 1.9;			//gamma
else if (i==15)		value = 8.3;			//neonates_v
//else if (i==16)		value = 2;				//r_time
else if (i==16)		value = 1.0;				//r_time   //CK// Changed!
else if (i==17)		value = 0.2;			//lambdaV
else if (i==18)		value = 0.2;			//lambdaF

else if (i==19)		value = 0.96;			//CK// Dummy param for checking!!

else if (i==20)		value = 0.01;		//CK// rain scaling parameter

else if (i==21)		value = 0.01;		//CK// temp scaling parameter

else if (i==22)		value = 0.01;		//CK// RH scaling parameter

else if (i==23)		value = 0.01;		//CK// average R(0)

else if (i==24)		value = 1.0;		//CK// RH scaling parameter

else if (i==25)		value = 1.0;		//CK// average R(0)

else if (i==26)		value = 30.0;		//CK// average R(0)

else if (i==27)		value = 0.3;		//CK// average R(0)

else if (i==28)		value = 0.035;		//CK// average R(0)

else if (i==29)		value = 0.035;		//CK// average R(0)

else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}

return value;
}


double fixed_patch(int i,int j)
{
double S_value=0;	double R_value=0;

if      (i==0)  {S_value = 100;				R_value = .20;	}
else if (i==1)	{S_value = 100;				R_value = .50;	}
else if (i==2)	{S_value = 300;				R_value = .60;	}
else if (i==3)	{S_value = 100;				R_value = 0;	}
else if (i==4)	{S_value = (1293.3/30);		R_value = .3;	}
else if (i==5)	{S_value = 200;				R_value = .1;	}
else if (i==6)	{S_value = 100;				R_value = .05;	}
else if (i==7)	{S_value = (35148/30);		R_value = .08;	}
else if (i==8)	{S_value = 100;				R_value = .05;	}
else if (i==9)	{S_value = 100;				R_value = .07;	}
else if (i==10)	{S_value = 100;				R_value = .08;	}
else if (i==11)	{S_value = 200;				R_value = .2;	}
else if (i==12)	{S_value = 200;				R_value = .1;	}
else if (i==13)	{S_value = 100;				R_value = .25;	}
else if (i==14)	{S_value = 100;				R_value = 0;	}
else if (i==15)	{S_value = 100;				R_value = 0;	}
else if (i==16)	{S_value = 100;				R_value = 0;	}

else { printf("i=%d\t j=%d\t PROBLEM WITH INDEX ON S(0) or R(0)!!\n",i,j);	getc(stdin);    return 0;	}

if		(j==1)	return S_value;
else if (j==3)	return R_value;
else { printf("PROBLEM WITH CHOOSING S(0) or R(0)!!\n");	return 0;	}

}
// ---------------------------------------------------------------------------------------------------------------- //
double start_pc(int i)
{
double pc_value=0;

	 if (i==0)	pc_value= 5.186043e+00;		else if (i==1)	pc_value= 1.601133e+00;
else if (i==2)	pc_value= 6.347635e-01;		else if (i==3)	pc_value= .373140e+00;
else if (i==4)	pc_value=-5.457952e-01;		else if (i==5)	pc_value= 2.441176e-01;
else if (i==6)	pc_value= 4.549583e-01;		else if (i==7)	pc_value= 4.288782e-01;
else if (i==8)	pc_value=-1.874400e-01;		else if (i==9)	pc_value= 2.059179e-01;
else if (i==10)	pc_value=-2.302962e-01;		else if (i==11)	pc_value=-2.235796e-01;
else if (i==12)	pc_value= 1.475449e-01;		else if (i==13)	pc_value=-1.769097e-01;
else if (i==14)	pc_value=-1.212636e-01;		else if (i==15)	pc_value=-1.272351e-01;
else if (i==16)	pc_value= 4.185948e-01;		else if (i==17)	pc_value=-1.060853e-01;
else if (i==18)	pc_value=-3.476973e-01;		else if (i==19)	pc_value= 9.517782e-01;
else if (i==20)	pc_value= 2.936443e-01;		else if (i==21)	pc_value= 1.013198e-01;
else if (i==22)	pc_value= 8.026273e-01;		else if (i==23)	pc_value=-1.248938e-01;
else if (i==24)	pc_value= 6.162489e-01;		else if (i==25)	pc_value= 7.884241e-01;
else if (i==26)	pc_value= 4.769538e-01;		else if (i==27)	pc_value=-8.913772e-01;
else if (i==28)	pc_value= 1.910217e-01;		else if (i==29)	pc_value= 5.366982e-01;
else if (i==30)	pc_value=-3.458366e-01;		else if (i==31)	pc_value=-2.682097e-01;
else if (i==32)	pc_value= 7.909581e-01;		else if (i==33)	pc_value=-3.420851e-01;
else if (i==34)	pc_value= 2.193495e-02;		else if (i==35)	pc_value= 1.685945e-01;

else printf("bad pc!!!\n");

return pc_value;

}

// ------------------------------------------------------------------------------------------- //
void load_fxd_parms(void *Paramstuff,int numb)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;
int i=1;
double parm_load[numb];
FILE *ftp_parm_load;
ftp_parm_load = fopen("/users/egoldwyn/chicago/gypsy/loadparm.dat","r");

if (ftp_parm_load==0)	{	printf("loadpc file open error\n");	getc(stdin);	}
while (!feof(ftp_parm_load))	{
	fscanf(ftp_parm_load,"%lf \n",&parm_load[i]);
	printf("parm_load(%d)=%e\n",i,parm_load[i]);
	Params->PARS[i]=parm_load[i];
	i++;
}//getc(stdin);*/
return;
}

// ------------------------------------------------------------------------------------------- //
void global_fixed_parms(void *Paramstuff)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

Params->PARS[1] = 1;											// dummy parm to differentiate between profile hood and maxhood
//Params->PARS[3] = 1;											// scaled nuV and nuR
//Params->PARS[7] = 3.0;											//CK//  beta = the size of accumulated rainfall window
Params->PARS[9] = 50.0;											//CK//  beta = the size of accumulated rainfall window


Params->PARS[10] = 0.002;		//ck// ratio for virus infection.  Trying to set it and see what happens

// mu_R (wont matter)
Params->PARS[8] = 5;			Params->PARS[9] = 5;			// gamma steps
//Params->PARS[11]= 0;			Params->PARS[12]= 0;			// noise variance
//Params->PARS[13]= 1.01;											// delta (fixed)
//Params->PARS[24]=1293.3/30;		Params->PARS[27]=35148/30;		// constant S(0)

}
// ---------------------------------------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------------------------------------- //
void random_restart_parms(void *Paramstuff,gsl_rng *r_seed,int num_adj_pars,int test,int pro)
{
STRUCTURE* Params;
Params = (STRUCTURE*) Paramstuff;

int i;
for (i=1;i<=num_adj_pars;i++)	{
	if ((i==2||i==3||i==4||i==5||i==6||i==7||i==9||i==10||i==11||i==12||i==13||i==14||i==15||i==16||i==17||i==18||i==19||i==20||i==21||i==22||i==23||i==24||i==25||i==26||i==27||i==28||i==29) && (i!=pro))	{
		if (i==3||i==6||i==13||i==14||i==21||i==22||i==23||i==26||i==29)	{	//CK// Logged fungus params ONLY
			Params->PARS[i] = pow(10,gsl_ran_flat(r_seed,Params->parm_low[i],Params->parm_high[i]));
		}
		else if (i==16||i==17||i==18||i==19||i==20||i==24||i==25||i==27||i==28)	{	//CK// Fungus params ONLY
			Params->PARS[i] = gsl_ran_flat(r_seed,Params->parm_low[i],Params->parm_high[i]);
		}
		else if (i==11||i==12)						{	// start with very low amounts of stochasticity
		//else if (i==12)						{	// start with very low amounts of stochasticity
			Params->PARS[i] = .01;
		}
		else if (i==9)						{	// start with very low amounts of stochasticity
			Params->PARS[i] = 50.0;
		}
		else if (i==7)						{	// start with very low amounts of stochasticity
			Params->PARS[i] = 10.0;
			//Params->PARS[i] = 5.0;
			//Params->PARS[i] = 3.0;

		}
		//else if (i==10)						{	//CK// Set ratio to experimentall measured value
		//	Params->PARS[i] = 0.002;
		//}
		else if (i==2||i==4||i==5||i==8||i==10||i==15)	{	//CK// set virus parameters to 0. NO VIRUS
			Params->PARS[i] = 0.0;
		}
		else {	printf("in bounds.h random_restart_parms: bad initial parameter!!!\n"); getc(stdin);	}
		
		if (test==99)	Params->PARS[i] = fixed_parm(i);				// for fixed init parms
		if (pro==1)		{	printf("initial parm(%d)=%e\n",i,Params->PARS[i]);	}
	}
	Params->MLE[i] = Params->PARS[i];
	//printf("init parm(%d)=%f\n",i,Params->PARS[i]);
}

}

