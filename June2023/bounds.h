double ls_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

if (i==0)			{	low = 0;			high = 5;		}	//initS //1-148

else if (i==1)		{	low = -11.5;			high = -5.5;		}	//initR meta 1 //0-0.004
else if (i==2)		{	low = -11.5;			high = -5.5;		}	//initR meta 2 //0-0.004
else if (i==3)		{	low = -11.5;			high = -5.5;		}	//initR meta 3 //0-0.004

else if (i==4)		{	low = -11.5;			high = -4.6;		}	//Fuller 2012 //virus decay //0.39 //muV
else if (i==5)		{	low = -1.2;			high = 1;		}	//virus heterogeneity
else if (i==6)		{	low = -4.6;			high = -0.0001;		}  //virus transmission //0.01 - 1

else if (i==7)		{	low = -11.5;			high = -5.5;		} 	//fungus transmission //0.00001 - 0.004

else if (i==8)		{	low = -4.6;			high = 4;		}	//VFSus //enhanced susceptibility //0-100

else if (i==9)		{	low = -7;			high = 0.7;		}	//Rsd	
else if (i==10)		{	low = -7;			high = 0.7;		}	//Fsd

else if (i==11)		{	low = -4.6;			high = -1.2;		}  // a_c_pop

else if (i==12)		{	low = -4.6;			high = -1.2;		}  // a_c_meta1
else if (i==13)		{	low = -4.6;			high = -1.2;		}  // a_c_meta2
else if (i==14)		{	low = -4.6;			high = -1.2;		}  // a_c_meta3

else if (i==15)		{	low = -4.6;			high = -1.2;		}  // a_c_sub //meta1
else if (i==16)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==17)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==18)		{	low = -4.6;			high = -1.2;		}  // a_c_sub

else if (i==19)		{	low = -4.6;			high = -1.2;		}  // a_c_sub //meta2
else if (i==20)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==21)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==22)		{	low = -4.6;			high = -1.2;		}  // a_c_sub

else if (i==23)		{	low = -4.6;			high = -1.2;		}  // a_c_sub //meta3
else if (i==24)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==25)		{	low = -4.6;			high = -1.2;		}  // a_c_sub
else if (i==26)		{	low = -4.6;			high = -1.2;		}  // a_c_sub

else if (i==27)		{		low = -8.5;			high = -0.0001;		} //m_c_pop

else if (i==28)		{		low = -8.5;			high = -0.0001;	} //m_c_meta1
else if (i==29)		{		low = -8.5;			high = -0.0001;	} //m_c_meta2
else if (i==30)		{		low = -8.5;			high = -0.0001;	} //m_c_meta3

else if (i==31)		{		low = -8.5;			high = -0.0001;		} //m_c_sub //meta1
else if (i==32)		{		low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==33)		{		low = -8.5;			high = -0.0001;		} //m_c_sub
else if (i==34)		{		low = -8.5;			high = -0.0001;	} //m_c_sub

else if (i==35)		{		low = -8.5;			high = -0.0001;		} //m_c_sub //meta2
else if (i==36)		{		low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==37)		{		low = -8.5;			high = -0.0001;		} //m_c_sub
else if (i==38)		{		low = -8.5;			high = -0.0001;		} //m_c_sub

else if (i==39)		{		low = -8.5;			high = -0.0001;	} //m_c_sub //meta3
else if (i==40)		{	low = -8.5;			high = -0.0001;		} //m_c_sub
else if (i==41)		{	low = -8.5;			high = -0.0001;		} //m_c_sub
else if (i==42)		{		low = -8.5;			high = -0.0001;	} //m_c_sub


else if (i==43)		{	low = -4.6;			high = -1.2;		}  // a_l_pop

else if (i==44)		{	low = -4.6;			high = -1.2;		}  // a_l_meta1
else if (i==45)		{	low = -4.6;			high = -1.2;		}  // a_l_meta2
else if (i==46)		{	low = -4.6;			high = -1.2;		}  // a_l_meta3

else if (i==47)		{	low = -4.6;			high = -1.2;		}  // a_l_sub //meta1
else if (i==48)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==49)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==50)		{	low = -4.6;			high = -1.2;		}  // a_l_sub

else if (i==51)		{	low = -4.6;			high = -1.2;		}  // a_l_sub //meta2
else if (i==52)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==53)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==54)		{	low = -4.6;			high = -1.2;		}  // a_l_sub

else if (i==55)		{	low = -4.6;			high = -1.2;		}  // a_l_sub //meta3
else if (i==56)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==57)		{	low = -4.6;			high = -1.2;		}  // a_l_sub
else if (i==58)		{	low = -4.6;			high = -1.2;		}  // a_l_sub

else if (i==59)		{	low = -8.5;			high = -0.0001;	} //m_l_pop

else if (i==60)		{		low = -8.5;			high = -0.0001;	} //m_l_meta1
else if (i==61)		{		low = -8.5;			high = -0.0001;	} //m_l_meta2
else if (i==62)		{		low = -8.5;			high = -0.0001;	} //m_l_meta3

else if (i==63)		{		low = -8.5;			high = -0.0001;		} //m_l_sub //meta1
else if (i==64)		{		low = -8.5;			high = -0.0001;		} //m_l_sub
else if (i==65)		{		low = -8.5;			high = -0.0001;		} //m_l_sub
else if (i==66)		{		low = -8.5;			high = -0.0001;		} //m_l_sub

else if (i==67)		{		low = -8.5;			high = -0.0001;		} //m_l_sub //meta2
else if (i==68)		{		low = -8.5;			high = -0.0001;		} //m_l_sub
else if (i==69)		{		low = -8.5;			high = -0.0001;		} //m_l_sub
else if (i==70)		{		low = -8.5;			high = -0.0001;		} //m_l_sub

else if (i==71)		{		low = -8.5;			high = -0.0001;	} //m_l_sub //meta3
else if (i==72)		{		low = -8.5;			high = -0.0001;		} //m_l_sub
else if (i==73)		{		low = -8.5;			high = -0.0001;	} //m_l_sub
else if (i==74)		{		low = -8.5;			high = -0.0001;		} //m_l_sub

//metapopulation four
else if (i==75)		{	low = 0;			high = 5;		} 	//initS //1-148
else if (i==76)		{	low = -9.2;			high = -0.1;	} 	//initV  //0 - .9
else if (i==77)		{	low = -11.5;			high = -4.6;		} 	//initR //0-0.01

//metapopulation five
else if (i==78)		{	low = 0;			high = 5;		} 	//initS //1-148
else if (i==79)		{	low = -9.2;			high = -0.7;	} 	//initV  //0 - .5

//metapopulation six
else if (i==80)		{	low = 0;			high = 5.5;		} 	//initS //1-250
else if (i==81)		{	low = -9.2;			high = -0.1;	} 	//initV  //0 - .9
else if (i==82)		{	low = -11.5;			high = -4.6;		} 	//initR //0-0.01

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}
}
// ------------------------------------------------------------------------------------ //
double step(int i)				// bounds on parameters for parhood line search
{
double step_size;

//metapopulation one
if (i==0)			{	step_size = 2;	}	//initS //1-148

else if (i==1)		{	step_size = 0.0001;	} 	//initR  //0-0.01
else if (i==2)		{	step_size = 0.0001;	} 	//initR  //0-0.01
else if (i==3)		{	step_size = 0.0001;	} 	//initR  //0-0.01

else if (i==4)		{	step_size = 0.05;	}	//virus decay
else if (i==5)		{	step_size = 0.05;	} 	//heterogeneity
else if (i==6)	{	step_size = 0.05;	}  //virus transmission //0.00001 - 0.01

else if (i==7)		{	step_size = 0.05;	}	//fungus transmission

else if (i==8) 	{	step_size = 0.05;	}	//VFSus //enhanced susceptibility 

else if (i==9)		{	step_size = 0.05;	}	//Rsd_exp
else if (i==10)		{	step_size = 0.05;	}	//Fsd_exp

else if (i==11)		{	step_size = 0.01;	} 	//a_c_pop

else if (i==12)		{	step_size = 0.01;	} 	//a_c_meta1
else if (i==13)		{	step_size = 0.01;	} 	//a_c_meta2
else if (i==14)		{	step_size = 0.01;	} 	//a_c_meta3

else if (i==15)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==16)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==17)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==18)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==19)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==20)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==21)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==22)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==23)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==24)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==25)		{	step_size = 0.01;	} 	//a_c_sub
else if (i==26)		{	step_size = 0.01;	} 	//a_c_sub

else if (i==27)		{	step_size = 0.0002;	}	//c_m_pop

else if (i==28)		{	step_size = 0.0002;	}	//c_m_meta1
else if (i==29)		{	step_size = 0.0002;	}	//c_m_meta2
else if (i==30)		{	step_size = 0.0002;	}	//c_m_meta3

else if (i==31)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==32)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==33)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==34)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==35)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==36)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==37)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==38)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==39)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==40)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==41)		{	step_size = 0.0002;	}	//c_m_sub
else if (i==42)		{	step_size = 0.0002;	}	//c_m_sub

else if (i==43)		{	step_size = 0.01;	} 	//a_l_pop

else if (i==44)		{	step_size = 0.01;	} 	//a_l_meta1
else if (i==45)		{	step_size = 0.01;	} 	//a_l_meta2
else if (i==46)		{	step_size = 0.01;	} 	//a_l_meta3

else if (i==47)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==48)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==49)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==50)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==51)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==52)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==53)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==54)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==55)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==56)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==57)		{	step_size = 0.01;	} 	//a_l_sub
else if (i==58)		{	step_size = 0.01;	} 	//a_l_sub

else if (i==59)		{	step_size = 0.0002;	}	//l_m_pop
else if (i==60)		{	step_size = 0.0002;	}	//l_m_meta1
else if (i==61)		{	step_size = 0.0002;	}	//l_m_meta2
else if (i==62)		{	step_size = 0.0002;	}	//l_m_meta3

else if (i==63)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==64)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==65)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==66)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==67)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==68)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==69)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==70)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==71)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==72)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==73)		{	step_size = 0.0002;	}	//l_m_sub
else if (i==74)		{	step_size = 0.0002;	}	//l_m_sub

//metapopulation four
else if (i==75)		{	step_size = 2;	}	//initS //1-148
else if (i==76)		{	step_size = 0.01;	}	//initV  //0 - .5
else if (i==77)		{	step_size = 0.0001;	} 	//initR  //0-0.01

//metapopulation five
else if (i==78)		{	step_size = 2;	}	//initS //1-148
else if (i==79)		{	step_size = 0.01;	} 	//initV  //0 - .5

//metapopulation six
else if (i==80)		{	step_size = 2;	}	//initS //1-148
else if (i==81)		{	step_size = 0.01;	}  	//initV  //0 - .5
else if (i==82)		{	step_size = 0.0001;	}	//initR //0-0.01

return step_size;
}
// ------------------------------------------------------------------------------------ //
double prior_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//metapopulation one
if (i==0)			{	low = 0;			high = 5000;	}	//initS fungus-only

else if (i==1)		{	low = 0;			high = 1;		}	//initR fungus-only
else if (i==2)		{	low = 0;			high = 1;		}	//initR virus-only
else if (i==3)		{	low = 0;			high = 1;		}	//initR fungus-virus

else if (i==4)		{	low = 0;			high = 5;		} 	//virus decay rate

else if (i==5) 	{	low = 0;			high = 10;		}	//heterogeneity
else if (i==6)	{	low = 0; 			high = 	10;	}	//virus transmission

else if (i==7) 	{	low = 0;			high = 1;		}	//fungus transmission

else if (i==8) 	{	low = 0;			high = 10000;	}	//VFSus //enhanced susceptibility 

else if (i==9)		{	low = 0;			high = 10;		}	//Rsd_exp
else if (i==10)		{	low = 0;			high = 10;		}	//Fsd_exp

else if (i==11)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==12)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==13)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==14)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==15)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==16)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==17)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==18)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==19)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==20)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==21)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==22)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==23)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==24)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==25)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==26)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==27)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidi
else if (i==28)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==29)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==30)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia

else if (i==31)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==32)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==33)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==34)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==35)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==36)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==37)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==38)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==39)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==40)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==41)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==42)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
//lar
else if (i==43)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==44)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==45)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==46)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==47)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==48)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==49)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==50)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==51)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==52)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==53)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==54)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==55)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==56)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==57)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal
else if (i==58)		{	low = 0;			high = 100;	} 	//con_mgr //rate of conidia dispersal

else if (i==59)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidi
else if (i==60)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==61)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==62)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia

else if (i==63)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==64)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==65)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==66)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==67)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==68)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==69)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==70)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==71)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==72)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==73)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
else if (i==74)		{	low = 0;			high = 100;		}	//a //distance dispersal parameter conidia
//metapopulation four
else if (i==75)		{	low = 0;			high = 5000;	} 	//initS
else if (i==76)		{	low = 0;			high = 1;		} 	//initV
else if (i==77)		{	low = 0;			high = 1;		} 	//initR

//metapopulation five
else if (i==78)		{	low = 0;			high = 5000;	}	//initS
else if (i==79)		{	low = 0;			high = 1;		} 	//initV

//metapopulation six
else if (i==80)		{	low = 0;			high = 5000;	} 	//initS
else if (i==81)		{	low = 0;			high = 1;		} 	//initV
else if (i==82)		{	low = 0;			high = 1;		} 	//initR

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PRIORS!!\n");	return 0;	}

/*/metapopulation one
if (i==0)			{	low = 0;			high = 5;		}	//initS fungus-only //1-148
else if (i==1)		{	low = 0;			high = 5;		}	//initS virus-only //1-148
else if (i==2)		{	low = 0;			high = 5;		}	//initS fungus-virus //1-148
else if (i==3)		{	low = 0;			high = 5;		}	//initS control //1-148

else if (i==4)		{	low = -9.2;			high = -0.7;	}	//initV fungus-only //0 - .5
else if (i==5)		{	low = -9.2;			high = -0.7;	}	//initV virus-only  //0 - .5
else if (i==6)		{	low = -9.2;			high = -0.7;	}	//initV fungus-virus  //0 - .5
else if (i==7)		{	low = -9.2;			high = -0.7;		}	//initV control  //0 - .5

else if (i==8)		{	low = -11.5;			high = -4.6;		}	//initR fungus-only //0-0.01
else if (i==9)		{	low = -11.5;			high = -4.6;		}	//initR virus-only //0-0.01
else if (i==10)		{	low = -11.5;			high = -4.6;		}	//initR fungus-virus //0-0.01
else if (i==11)		{	low = -11.5;			high = -4.6;		}	//initR control //0-0.01

//metapopulation two
else if (i==12)		{	low = 0;			high = 5;		}	//initS fungus-only //1-148
else if (i==13)		{	low = 0;			high = 5;		}	//initS virus-only //1-148
else if (i==14)		{	low = 0;			high = 5;		}	//initS fungus-virus //1-148
else if (i==15)		{	low = 0;			high = 5;		}	//initS control //1-148

else if (i==16)		{	low = -9.2;			high = -0.7;		}	//initV fungus-only  //0 - .5
else if (i==17)		{	low = -9.2;			high = -0.7;	}	//initV virus-only  //0 - .5
else if (i==18)		{	low = -9.2;			high = -0.7;	}	//initV fungus-virus  //0 - .5
else if (i==19)		{	low = -9.2;			high = -0.7;		}	//initV control  //0 - .5

else if (i==20)		{	low = -11.5;			high = -4.6;		}	//initR fungus-only //0-0.01
else if (i==21)		{	low = -11.5;			high = -4.6;		}	//initR virus-only //0-0.01
else if (i==22)		{	low = -11.5;			high = -4.6;		}	//initR fungus-virus //0-0.01
else if (i==23)		{	low = -11.5;			high = -4.6;		}	//initR control //0-0.01

//metapopulation three
else if (i==24)		{	low = 0;			high = 5;		}	//initS fungus-only //1-148
else if (i==25)		{	low = 0;			high = 5;		}	//initS virus-only //1-148
else if (i==26)		{	low = 0;			high = 5;		}	//initS fungus-virus //1-148
else if (i==27)		{	low = 0;			high = 5;		}	//initS control //1-148

else if (i==28)		{	low = -9.2;			high = -0.7;		}	//initV fungus-only  //0 - .5
else if (i==29)		{	low = -9.2;			high = -0.7;	}	//initV virus-only  //0 - .5
else if (i==30)		{	low = -9.2;			high = -0.7;	}	//initV fungus-virus  //0 - .5
else if (i==31)		{	low = -9.2;			high = -0.7;		}	//initV control  //0 - .5

else if (i==32)		{	low = -11.5;			high = -4.6;		}	//initR fungus-only //0-0.01
else if (i==33)		{	low = -11.5;			high = -4.6;		}	//initR virus-only //0-0.01
else if (i==34)		{	low = -11.5;			high = -4.6;		}	//initR fungus-virus //0-0.01
else if (i==35)		{	low = -11.5;			high = -4.6;		}	//initR control //0-0.01

//metapopulation four
else if (i==36)		{	low = 0;			high = 5;		} 	//initS //1-148
else if (i==37)		{	low = -9.2;			high = -0.1;	} 	//initV  //0 - .9
else if (i==38)		{	low = -11.5;			high = -4.6;		} 	//initR //0-0.01

//metapopulation five
else if (i==39)		{	low = 0;			high = 5;		} 	//initS //1-148
else if (i==40)		{	low = -9.2;			high = -0.7;	} 	//initV  //0 - .5
else if (i==41)		{	low = -11.5;			high = -4.6;		} 	//initR //0-0.01

//metapopulation six
else if (i==42)		{	low = 0;			high = 5.5;		} 	//initS //1-250
else if (i==43)		{	low = -9.2;			high = -0.1;	} 	//initV  //0 - .9
else if (i==44)		{	low = -11.5;			high = -4.6;		} 	//initR //0-0.01

//conidia dispersal
else if (i==45)		{	low = -8.5;		high = 1.6;		} 	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==46)		{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia

//larval dispersal
//meta 1
else if (i==47)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==48)		{	low = -8.5;			high = 1.16;		}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==49)		{	low = -8.5;			high = 1.16;		}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==50)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==51)		{	low = -4.6;			high = -1.2;		} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==52)		{	low = -4.6;			high = -1.2;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==53)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==54)		{	low = -4.6;			high = -1.2;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3

//meta 2
else if (i==55)		{	low = -8.5;			high = 1.16;		}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==56)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==57)		{	low = -8.5;			high = 1.16;		}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==58)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==59)		{	low = -4.6;			high = -1.2;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==60)		{	low = -4.6;			high = -1.2;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==61)		{	low = -4.6;			high = -1.2;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==62)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3

//meta 3
else if (i==63)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==64)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==65)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==66)		{	low = -8.5;			high = 1.16;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==67)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==68)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==69)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==70)		{	low = -4.6;			high = -1.2;	}	//a2 //distance dispersal parameter larvae //0.01-0.3

//coifection
else if (i==71) 	{	low = -4.6;			high = -.1;		}	//coinf_V //coinfecteds produce what proportion of OBs/conidia //0.01-.9
else if (i==72) 	{	low = -4.6;			high = 4;		}	//VFSus //enhanced susceptibility //0-100

//stochasticity
else if (i==73)		{	low = -7;			high = 0.7;		}	//Rsd_exp
else if (i==74)		{	low = -7;			high = 0.7;		}	//Fsd_exp
else if (i==75)		{	low = -7;			high = 0.7;		}	//Rsd_obs
else if (i==76)		{	low = -7;			high = 0.7;		}	//Fsd_obs

//virus 
else if (i==77)		{	low = -11.5;			high = -4.6;		}	//decay rate
else if (i==78)		{	low = -1.2;			high = 1;		}	//heterogeneity

else if (i==79)		{	low = -11.5;			high = -4.6;		} 	//fungus transmission //0.00001 - 

//conidia dispersal
//meta 1
else if (i==80)		{	low = -8.5;			high = 1.16;		}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==81)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==82)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==83)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5

else if (i==84)		{	low = -4.6;			high = -1.2;		}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==85)		{	low = -4.6;			high = -1.2;		} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==86)		{	low = -4.6;			high = -1.2;		} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==87)		{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3

//meta 2
else if (i==88)		{	low = -8.5;			high = 1.16;		}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==89)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==90)		{	low = -8.5;			high = 1.16;		}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==91)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5

else if (i==92)		{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==93)		{	low = -4.6;			high = -1.2;		}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==94)		{	low = -4.6;			high = -1.2;	} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==95)		{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3

//meta 3
else if (i==96)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==97)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==98)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==99)		{	low = -8.5;			high = 1.16;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5

else if (i==100)	{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==101)	{	low = -4.6;			high = -1.2;		}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==102)	{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==103)	{	low = -4.6;			high = -1.2;	}	//a //distance dispersal parameter conidia //0.01-0.3

//larval dispersal POP
else if (i==104)		{	low = -8.5;			high = 1.16;		} 	//m_l_pop //0.0002 - 5
else if (i==105)		{	low = -4.6;			high = -1.2;		}	//a_l_pop //0.01-0.3

else if (i==106)		{	low = -8.5;			high = -2.3;		}  //virus transmission //0.0002 - 0.1

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}
}
// ------------------------------------------------------------------------------------ //
double step(int i)				// bounds on parameters for parhood line search
{
double step_size;

//metapopulation one
if (i==0)			{	step_size = 2;	}	//initS fungus-only //1-148
else if (i==1)		{	step_size = 2;	}	//initS virus-only //1-148
else if (i==2)		{	step_size = 2;	}	//initS fungus-virus //1-148
else if (i==3)		{	step_size = 2;	}	//initS control //1-148

else if (i==4)		{	step_size = 0.01;	}	//initV fungus-only  //0 - .5
else if (i==5)		{	step_size = 0.01;	}	//initV virus-only  //0 - .5
else if (i==6)		{	step_size = 0.01;	}	//initV fungus-virus  //0 - .5
else if (i==7)		{	step_size = 0.01;	}	//initV control  //0 - .5

else if (i==8)		{	step_size = 0.0001;	}	//initR fungus-only //0-0.01
else if (i==9)		{	step_size = 0.0001;	}	//initR virus-only //0-0.01
else if (i==10)		{	step_size = 0.0001;	}	//initR fungus-virus //0-0.01
else if (i==11)		{	step_size = 0.0001;	}	//initR control //0-0.01

//metapopulation two
else if (i==12)		{	step_size = 2;	}	//initS fungus-only //1-148
else if (i==13)		{	step_size = 2;	}	//initS virus-only //1-148
else if (i==14)		{	step_size = 2;	}	//initS fungus-virus //1-148
else if (i==15)		{	step_size = 2;	}	//initS control //1-148

else if (i==16)		{	step_size = 0.01;	}	//initV fungus-only  //0 - .5
else if (i==17)		{	step_size = 0.01;	}	//initV virus-only  //0 - .5
else if (i==18)		{	step_size = 0.01;	}	//initV fungus-virus  //0 - .5
else if (i==19)		{	step_size = 0.01;	}	//initV control  //0 - .5

else if (i==20)		{	step_size = 0.0001;	}	//initR fungus-only //0-0.01
else if (i==21)		{	step_size = 0.0001;	}	//initR virus-only //0-0.01
else if (i==22)		{	step_size = 0.0001;	}	//initR fungus-virus //0-0.01
else if (i==23)		{	step_size = 0.0001;	}	//initR control //0-0.01

//metapopulation three
else if (i==24)		{	step_size = 2;	}	//initS fungus-only //1-148
else if (i==25)		{	step_size = 2;	}	//initS virus-only //1-148
else if (i==26)		{	step_size = 2;	}	//initS fungus-virus //1-148
else if (i==27)		{	step_size = 2;	}	//initS control //1-148

else if (i==28)		{	step_size = 0.01;	}	//initV fungus-only  //0 - .5
else if (i==29)		{	step_size = 0.01;	}	//initV virus-only  //0 - .5
else if (i==30)		{	step_size = 0.01;	}	//initV fungus-virus  //0 - .5
else if (i==31)		{	step_size = 0.01;	}	//initV control  //0 - .5

else if (i==32)		{	step_size = 0.0001;	}	//initR fungus-only //0-0.01
else if (i==33)		{	step_size = 0.0001;	}	//initR virus-only //0-0.01
else if (i==34)		{	step_size = 0.0001;	}	//initR fungus-virus //0-0.01
else if (i==35)		{	step_size = 0.0001;	}	//initR control //0-0.01

//metapopulation four
else if (i==36)		{	step_size = 2;	}	//initS //1-148
else if (i==37)		{	step_size = 0.01;	}	//initV  //0 - .5
else if (i==38)		{	step_size = 0.0001;	} 	//initR  //0-0.01

//metapopulation five
else if (i==39)		{	step_size = 2;	}	//initS //1-148
else if (i==40)		{	step_size = 0.01;	} 	//initV  //0 - .5
else if (i==41)		{	step_size = 0.0001;	} 	//initR //0-0.01

//metapopulation six
else if (i==42)		{	step_size = 2;	}	//initS //1-148
else if (i==43)		{	step_size = 0.01;	}  	//initV  //0 - .5
else if (i==44)		{	step_size = 0.0001;	}	//initR //0-0.01

//conidia dispersal
else if (i==45)		{	step_size = 0.0002;	}  	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==46)		{	step_size = 0.01;	} 	//a //distance dispersal parameter //0.01-0.3

//larval dispersal
//meta 1
else if (i==47)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==48)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==49)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==50)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==51)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==52)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==53)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==54)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3

//meta 2
else if (i==55)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==56)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==57)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==58)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==59)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==60)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==61)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==62)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3

//meta 3
else if (i==63)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==64)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==65)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5
else if (i==66)		{	step_size = 0.0002;	}	//lar_mgr //rate of larval dispersal //0.0002 - 5

else if (i==67)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==68)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==69)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3
else if (i==70)		{	step_size = 0.01;	} 	//a2 //distance dispersal parameter larvae //0.01-0.3

//coifection
else if (i==71) 	{	step_size = 0.05;	}	//coinf_V //coinfecteds produce what proportion of OBs/conidia
else if (i==72) 	{	step_size = 0.05;	}	//VFSus //enhanced susceptibility 

//stochasticity
else if (i==73)		{	step_size = 0.05;	}	//Rsd_exp
else if (i==74)		{	step_size = 0.05;	}	//Fsd_exp
else if (i==75)		{	step_size = 0.05;	}	//Rsd_obs
else if (i==75)		{	step_size = 0.05;	}	//Fsd_obs

//virus
else if (i==77)		{	step_size = 0.05;	}	//virus decay

else if (i==78)		{	step_size = 0.05;	} 	//heterogeneity

else if (i==79)		{	step_size = 0.05;	}	//fungus transmission

//conidia dispersal
//meta 1
else if (i==80)		{	step_size = 0.0002;	}	//con_mgr //rate of conidia dispersal //0.0002 - 5
else if (i==81)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==82)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==83)		{	step_size = 0.0002;	}	 //0.0002 - 5

else if (i==84)		{	step_size = 0.01;	} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==85)		{	step_size = 0.01;	} 	 //0.01-0.3
else if (i==86)		{	step_size = 0.01;	} 	 //0.01-0.3
else if (i==87)		{	step_size = 0.01;	} 	 //0.01-0.3

//meta 2
else if (i==88)		{	step_size = 0.0002;	}	//con_mgr //rate of conidia dispersal
else if (i==89)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==90)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==91)		{	step_size = 0.0002;	}	 //0.0002 - 5

else if (i==92)		{	step_size = 0.01;	} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==93)		{	step_size = 0.05;	} 	 //0.01-0.3
else if (i==94)		{	step_size = 0.05;	} 	 //0.01-0.3
else if (i==95)		{	step_size = 0.05;	} 	 //0.01-0.3

//meta 3
else if (i==96)		{	step_size = 0.0002;	}	//con_mgr //rate of conidia dispersal
else if (i==97)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==98)		{	step_size = 0.0002;	}	 //0.0002 - 5
else if (i==99)		{	step_size = 0.0002;	}	 //0.0002 - 5

else if (i==100)	{	step_size = 0.05;	} 	//a //distance dispersal parameter conidia //0.01-0.3
else if (i==101)	{	step_size = 0.05;	} 	 //0.01-0.3
else if (i==102)	{	step_size = 0.05;	} 	 //0.01-0.3
else if (i==103)	{	step_size = 0.05;	} 	 //0.01-0.3

else if (i==104)	{	step_size = 0.0002;	}  //m_l_pop //0.0002 - 5
else if (i==105)	{	step_size = 0.05;	}  //a_l_pop //0.01-0.3

else if (i==106)	{	step_size = 0.05;	}  //virus transmission //0.00001 - 0.01

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

//conidia dispersal
else if (i==45)		{	low = 0;			high = 10000;	} 	//con_mgr //rate of conidia dispersal
else if (i==46)		{	low = 0;			high = 1;		}	//a //distance dispersal parameter conidia

//larval dispersal
//meta 1
else if (i==47)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==48)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==49)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==50)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal

else if (i==51)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==52)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==53)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==54)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae

//meta 2
else if (i==55)		{	low = 0;			high = 100;	}	//lar_mgr //rate of larval dispersal
else if (i==56)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==57)		{	low = 0;			high = 100;	}	//lar_mgr //rate of larval dispersal
else if (i==58)		{	low = 0;			high = 100;			}	//lar_mgr //rate of larval dispersal

else if (i==59)		{	low = 0;			high = 100;			} 	//a2 //distance dispersal parameter larvae
else if (i==60)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==61)		{	low = 0;			high = 100;			} 	//a2 //distance dispersal parameter larvae
else if (i==62)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae

//meta 3
else if (i==63)		{	low = 0;			high = 100;			}	//lar_mgr //rate of larval dispersal
else if (i==64)		{	low = 0;			high = 100;			}	//lar_mgr //rate of larval dispersal
else if (i==65)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal
else if (i==66)		{	low = 0;			high = 100;		}	//lar_mgr //rate of larval dispersal

else if (i==67)		{	low = 0;			high = 100;			} 	//a2 //distance dispersal parameter larvae
else if (i==68)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==69)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae
else if (i==70)		{	low = 0;			high = 100;		} 	//a2 //distance dispersal parameter larvae

//coifection
else if (i==71) 	{	low = 0;			high = 1;		}	//coinf_V //coinfecteds produce what proportion of OBs/conidia
else if (i==72) 	{	low = 0;			high = 10000;	}	//VFSus //enhanced susceptibility 

//stochasticity
else if (i==73)		{	low = 0;			high = 10;		}	//Rsd_exp
else if (i==74)		{	low = 0;			high = 10;		}	//Fsd_exp
else if (i==75)		{	low = 0;			high = 10;		}	//Rsd_obs
else if (i==76)		{	low = 0;			high = 10;		}	//Fsd_obs

//virus
else if (i==77)		{	low = 0;			high = 5;		} 	//virus decay rate

else if (i==78) 	{	low = 0;			high = 10;		}	//heterogeneity

else if (i==79) 	{	low = 0;			high = 1;		}	//fungus transmission

//conidia dispersal
//meta 1
else if (i==80)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==81)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==82)		{	low = 0;			high = 100;		}	
else if (i==83)		{	low = 0;			high = 100;		}	

else if (i==84)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==85)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==86)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==87)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia

//meta 2
else if (i==88)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==89)		{	low = 0;			high = 100;		}	
else if (i==90)		{	low = 0;			high = 100;		}	
else if (i==91)		{	low = 0;			high = 100;		}	

else if (i==92)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==93)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==94)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==95)		{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia

//meta 3
else if (i==96)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==97)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==98)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal
else if (i==99)		{	low = 0;			high = 100;		}	//con_mgr //rate of conidia dispersal

else if (i==100)	{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==101)	{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==102)	{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia
else if (i==103)	{	low = 0;			high = 100;		} 	//a //distance dispersal parameter conidia

else if (i==104)	{	low = 0;			high = 100;		}	//m_l_pop
else if (i==105)	{	low = 0;			high = 100;		}	//a_l_pop

else if (i==106)	{	low = 0; 			high = 	10;	}	//virus transmission
*/
}