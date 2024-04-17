double ls_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//SAME FOR ALL MODELS - CURRENTLY USING

//-----INITS-------
//STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
if (i==0)			{   low = -15;        high = 4.3;     }	//POP           //0.01-75     //****

//-----INITR------
//STARTING          {   low = -11.5;        high = -1;   }                   //0.00001-0.36  
else if (i==1)		{   low = -20;        high = 0;      }	//POP           //2.06115362e-9-1  //****
else if (i==2)		{   low = -20;        high = 0;      }	//META 1        //2.06115362e-9-1
else if (i==3)		{   low = -20;        high = 0;      }	//META 2        //2.06115362e-9-1
else if (i==4)		{   low = -20;        high = 0;      }	//META 3        //2.06115362e-9-1
else if (i==5)		{   low = -20;        high = 0;      }	//META 1 SUB 1  //2.06115362e-9-1
else if (i==6)		{   low = -20;        high = 0;      }	//META 2 SUB 1  //2.06115362e-9-1
else if (i==7)		{   low = -20;        high = 0;      }	//META 2 SUB 2  //2.06115362e-9-1
else if (i==8)		{   low = -20;        high = 0;      }	//META 2 SUB 3  //2.06115362e-9-1
else if (i==9)		{   low = -20;        high = 0;      }	//META 2 SUB 4  //2.06115362e-9-1
else if (i==10)		{   low = -20;        high = 0;      }	//META 3 SUB 1  //2.06115362e-9-1
else if (i==11)		{   low = -20;        high = 0;      }	//META 3 SUB 2  //2.06115362e-9-1
else if (i==12)		{   low = -20;        high = 0;      }	//META 3 SUB 3  //2.06115362e-9-1
else if (i==13)		{	low = -20;		  high = 0;	     }	//META 3 SUB 4  //2.06115362e-9-1

//-----VIRUS DECAY muV------
//STARTING          {   low = -9;           high = 2.3;     }                   //0.0001-10
else if (i==14)		{   low = -9;           high = 2.3;     }	//POP           //0.0001-10     //****

//-----VIRUS HETERO CV-----
//STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
else if (i==15)		{   low = -9;           high = 3;       }	//POP           //0.0001-20     //****

//-----VIRUS TRANS nuV----
//STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
else if (i==16)		{   low = -9;           high = 3;       }   //POP           //0.0001-20     //****

//-----FUNGUS TRANS nuF-----
//STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36
else if (i==17)		{   low = -11.5;        high = -1;      }   //POP           //0.00001-0.36  //****

//-----RSTOCH-----
//STARTING          {   low = -11.5;        high = 2.3;       }                  //0.00001-10
else if (i==18)		{   low = -20;        high = 2.3;       }	//POP	        //0.00001-10    //****

//-----FSTOCH-----
//STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

//-----CONIDIA 1/AVG DIST DISP c_a-----
//STARTING          {   low = -6.9;        high = 4.6;     }                   //0.00001-100
else if (i==20)		{	low = -10;		    high = 1;     }   //POP           //0.00001-100
else if (i==21)		{	low = -10;		    high = 1;     }   //META 1        //0.00001-100
else if (i==22)		{	low = -10;	        high = 1;     }   //META 2        //0.00001-100
else if (i==23)		{	low = -10;	        high = 1;     }   //META 3        //0.00001-100
else if (i==24)		{	low = -10;		    high = 1;     }   //META 1 SUB 1  //0.00001-100
else if (i==25)		{	low = -10;		    high = 1;     }   //META 1 SUB 2  //0.00001-100
else if (i==26)		{	low = -10;		    high = 1;     }   //META 1 SUB 3  //0.00001-100
else if (i==27)		{	low = -10;		    high = 1;     }   //META 1 SUB 4  //0.00001-100
else if (i==28)		{	low = -10;		    high = 1;     }   //META 2 SUB 1  //0.00001-100
else if (i==29)		{	low = -10;		    high = 1;     }   //META 2 SUB 2  //0.00001-100
else if (i==30)		{	low = -10;		    high = 1;     }   //META 2 SUB 3  //0.00001-100
else if (i==31)		{	low = -10;		    high = 1;     }   //META 2 SUB 4  //0.00001-100
else if (i==32)		{	low = -10;		    high = 1;     }   //META 3 SUB 1  //0.00001-100
else if (i==33)		{	low = -10;		    high = 1;     }   //META 3 SUB 2  //0.00001-100
else if (i==34)		{	low = -10;		    high = 1;     }   //META 3 SUB 3  //0.00001-100
else if (i==35)		{	low = -10;		    high = 1;     }   //META 3 SUB 4  //0.00001-100

//-----CONIDIA FRAC SUCCESSFUL DISP c_m----- 
//STARTING          {   low = 0.000001;			high = 1;	}                   //non-log
else if (i==36)		{	low = 0.000001;			high = 1;	}   //POP
else if (i==37)		{	low = 0.000001;			high = 1;	}   //META 1
else if (i==38)		{	low = 0.000001;			high = 1;	}   //META 2
else if (i==39)		{	low = 0.000001;			high = 1;	}   //META 3
else if (i==40)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 1
else if (i==41)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 2
else if (i==42)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 3
else if (i==43)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 4
else if (i==44)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 1
else if (i==45)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 2 
else if (i==46)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 3
else if (i==47)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 4
else if (i==48)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 1
else if (i==49)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 2
else if (i==50)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 3
else if (i==51)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 4

//-----LARVAE AVG DIST DISP l_a-----
//STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100   
else if (i==52)		{	low = -10;		    high = 1;     }   //POP           //0.00001-100   //****
else if (i==53)		{	low = -10;		    high = 1;     }   //META 1        //0.00001-100
else if (i==54)		{	low = -10;		    high = 1;     }  //META 2        //0.00001-100
else if (i==55)		{	low = -10;		    high = 1;     }   //META 3        //0.00001-100
else if (i==56)		{	low = -10;		    high = 1;     }   //META 1 SUB 1  //0.00001-100
else if (i==57)		{	low = -10;		    high = 1;     }   //META 1 SUB 2  //0.00001-100
else if (i==58)		{	low = -10;		    high = 1;     }   //META 1 SUB 3  //0.00001-100
else if (i==59)		{	low = -10;		    high = 1;     }   //META 1 SUB 4  //0.00001-100
else if (i==60)		{	low = -10;		    high = 1;     }   //META 2 SUB 1  //0.00001-100
else if (i==61)		{	low = -10;		    high = 1;     }   //META 2 SUB 2  //0.00001-100
else if (i==62)		{	low = -10;		    high = 1;     }   //META 2 SUB 3  //0.00001-100
else if (i==63)		{	low = -10;  	    high = 1;     }   //META 2 SUB 4  //0.00001-100
else if (i==64)		{	low = -10;		    high = 1;     }   //META 3 SUB 1  //0.00001-100
else if (i==65)		{	low = -10;		    high = 1;     }   //META 3 SUB 2  //0.00001-100
else if (i==66)		{	low = -10;		    high = 1;     }   //META 3 SUB 3  //0.00001-100
else if (i==67)		{	low = -10;  	    high = 1;     }   //META 3 SUB 4  //0.00001-100

//-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
//STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
else if (i==68)		{	low = 0.00000001;			high = 1;	}   //POP                           //****
else if (i==69)		{	low = 0.00000001;			high = 1;	}   //META 1
else if (i==70)		{	low = 0.00000001;			high = 1;	}   //META 2
else if (i==71)		{	low = 0.00000001;			high = 1;	}   //META 3
else if (i==72)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 1
else if (i==73)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 2
else if (i==74)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 3
else if (i==75)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 4
else if (i==76)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 1
else if (i==77)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 2 
else if (i==78)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 3
else if (i==79)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 4
else if (i==80)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 1
else if (i==81)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 2
else if (i==82)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 3
else if (i==83)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 4

//-----OBSERVATIONAL-----
//-----META 4-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==84)		{	low = 0;			high = 5;       } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==85)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0.0001-0.9

//STARTING          {   low = -11.5;		high = -4.6;	}   //INITR         //0.00001-0.01
else if (i==86)		{	low = -11.5;		high = -4.6;    } 	//INITR         //0.00001-0.01

//-----META 5-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==87)		{	low = 0;			high = 5;       } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==88)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0-0.9

//-----META 6-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==89)		{	low = 0;			high = 5;     } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==90)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0.0001-0.9

//STARTING          {   low = -11.5;		high = -4.6;	}   //INITR         //0.00001-0.01
else if (i==91)		{	low = -11.5;		high = -4.6;	} 	//INITR         //0.00001-0.01

    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}

}
// ------------------------------------------------------------------------------------ //

double param_bound(int i,int j)	
{
double low;
double high;

//SAME FOR ALL MODELS - CURRENTLY USING

//-----INITS-------
//STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
if (i==0)			{   low = -20;        high = 10;     }	//POP           //0.01-75     //****

//-----INITR------
//STARTING          {   low = -11.5;        high = -1;   }                   //0.00001-0.36  
else if (i==1)		{   low = -20;        high = 0;      }	//POP           //2.06115362e-9-1  //****
else if (i==2)		{   low = -20;        high = 0;      }	//META 1        //2.06115362e-9-1
else if (i==3)		{   low = -20;        high = 0;      }	//META 2        //2.06115362e-9-1
else if (i==4)		{   low = -20;        high = 0;      }	//META 3        //2.06115362e-9-1
else if (i==5)		{   low = -20;        high = 0;      }	//META 1 SUB 1  //2.06115362e-9-1
else if (i==6)		{   low = -20;        high = 0;      }	//META 2 SUB 1  //2.06115362e-9-1
else if (i==7)		{   low = -20;        high = 0;      }	//META 2 SUB 2  //2.06115362e-9-1
else if (i==8)		{   low = -20;        high = 0;      }	//META 2 SUB 3  //2.06115362e-9-1
else if (i==9)		{   low = -20;        high = 0;      }	//META 2 SUB 4  //2.06115362e-9-1
else if (i==10)		{   low = -20;        high = 0;      }	//META 3 SUB 1  //2.06115362e-9-1
else if (i==11)		{   low = -20;        high = 0;      }	//META 3 SUB 2  //2.06115362e-9-1
else if (i==12)		{   low = -20;        high = 0;      }	//META 3 SUB 3  //2.06115362e-9-1
else if (i==13)		{	low = -20;		  high = 0;	     }	//META 3 SUB 4  //2.06115362e-9-1

//-----VIRUS DECAY muV------
//STARTING          {   low = -9;           high = 2.3;     }                   //0.0001-10
else if (i==14)		{   low = -20;           high = 2.3;     }	//POP           //0.0001-10     //****

//-----VIRUS HETERO CV-----
//STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
else if (i==15)		{   low = -23;           high = 3;       }	//POP           //0.0001-20     //****

//-----VIRUS TRANS nuV----
//STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
else if (i==16)		{   low = -20;           high = 3;       }   //POP           //0.0001-20     //****

//-----FUNGUS TRANS nuF-----
//STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36
else if (i==17)		{   low = -11.5;        high = -1;      }   //POP           //0.00001-0.36  //****

//-----RSTOCH-----
//STARTING          {   low = -11.5;        high = 2.3;       }                  //0.00001-10
else if (i==18)		{   low = -20;        high = 10;       }	//POP	        //0.00001-10    //****

//-----FSTOCH-----
//STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
else if (i==19)		{   low = -20;        high = 10;       }	//POP           //0.00001-20    //****

//-----CONIDIA 1/AVG DIST DISP c_a-----
//STARTING          {   low = -6.9;        high = 4.6;     }                   //0.00001-100
else if (i==20)		{	low = -20;		    high = 10;     }   //POP           //0.00001-100
else if (i==21)		{	low = -20;		    high = 10;     }   //META 1        //0.00001-100
else if (i==22)		{	low = -20;	        high = 10;     }   //META 2        //0.00001-100
else if (i==23)		{	low = -20;	        high = 10;     }   //META 3        //0.00001-100
else if (i==24)		{	low = -20;		    high = 10;     }   //META 1 SUB 1  //0.00001-100
else if (i==25)		{	low = -20;		    high = 10;     }   //META 1 SUB 2  //0.00001-100
else if (i==26)		{	low = -20;		    high = 10;     }   //META 1 SUB 3  //0.00001-100
else if (i==27)		{	low = -20;		    high = 10;     }   //META 1 SUB 4  //0.00001-100
else if (i==28)		{	low = -20;		    high = 10;     }   //META 2 SUB 1  //0.00001-100
else if (i==29)		{	low = -20;		    high = 10;     }   //META 2 SUB 2  //0.00001-100
else if (i==30)		{	low = -20;		    high = 10;     }   //META 2 SUB 3  //0.00001-100
else if (i==31)		{	low = -20;		    high = 10;     }   //META 2 SUB 4  //0.00001-100
else if (i==32)		{	low = -20;		    high = 10;     }   //META 3 SUB 1  //0.00001-100
else if (i==33)		{	low = -20;		    high = 10;     }   //META 3 SUB 2  //0.00001-100
else if (i==34)		{	low = -20;		    high = 10;     }   //META 3 SUB 3  //0.00001-100
else if (i==35)		{	low = -20;		    high = 10;     }   //META 3 SUB 4  //0.00001-100

//-----CONIDIA FRAC SUCCESSFUL DISP c_m----- 
//STARTING          {   low = 0.000001;			high = 1;	}                   //non-log
else if (i==36)		{	low = 0.000001;			high = 1;	}   //POP
else if (i==37)		{	low = 0.000001;			high = 1;	}   //META 1
else if (i==38)		{	low = 0.000001;			high = 1;	}   //META 2
else if (i==39)		{	low = 0.000001;			high = 1;	}   //META 3
else if (i==40)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 1
else if (i==41)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 2
else if (i==42)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 3
else if (i==43)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 4
else if (i==44)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 1
else if (i==45)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 2 
else if (i==46)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 3
else if (i==47)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 4
else if (i==48)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 1
else if (i==49)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 2
else if (i==50)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 3
else if (i==51)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 4

//-----LARVAE AVG DIST DISP l_a-----
//STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100   
else if (i==52)		{	low = -20;		    high = 10;     }   //POP           //0.00001-100   //****
else if (i==53)		{	low = -20;		    high = 10;     }   //META 1        //0.00001-100
else if (i==54)		{	low = -20;		    high = 10;     }  //META 2        //0.00001-100
else if (i==55)		{	low = -20;		    high = 10;     }   //META 3        //0.00001-100
else if (i==56)		{	low = -20;		    high = 10;     }   //META 1 SUB 1  //0.00001-100
else if (i==57)		{	low = -20;		    high = 10;     }   //META 1 SUB 2  //0.00001-100
else if (i==58)		{	low = -20;		    high = 10;     }   //META 1 SUB 3  //0.00001-100
else if (i==59)		{	low = -20;		    high = 10;     }   //META 1 SUB 4  //0.00001-100
else if (i==60)		{	low = -20;		    high = 10;     }   //META 2 SUB 1  //0.00001-100
else if (i==61)		{	low = -20;		    high = 10;     }   //META 2 SUB 2  //0.00001-100
else if (i==62)		{	low = -20;		    high = 10;     }   //META 2 SUB 3  //0.00001-100
else if (i==63)		{	low = -20;  	    high = 10;     }   //META 2 SUB 4  //0.00001-100
else if (i==64)		{	low = -20;		    high = 10;     }   //META 3 SUB 1  //0.00001-100
else if (i==65)		{	low = -20;		    high = 10;     }   //META 3 SUB 2  //0.00001-100
else if (i==66)		{	low = -20;		    high = 10;     }   //META 3 SUB 3  //0.00001-100
else if (i==67)		{	low = -20;  	    high = 10;     }   //META 3 SUB 4  //0.00001-100

//-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
//STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
else if (i==68)		{	low = 0.00000001;			high = 1;	}   //POP                           //****
else if (i==69)		{	low = 0.00000001;			high = 1;	}   //META 1
else if (i==70)		{	low = 0.00000001;			high = 1;	}   //META 2
else if (i==71)		{	low = 0.00000001;			high = 1;	}   //META 3
else if (i==72)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 1
else if (i==73)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 2
else if (i==74)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 3
else if (i==75)		{	low = 0.00000001;			high = 1;	}   //META 1 SUB 4
else if (i==76)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 1
else if (i==77)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 2 
else if (i==78)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 3
else if (i==79)		{	low = 0.00000001;			high = 1;	}   //META 2 SUB 4
else if (i==80)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 1
else if (i==81)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 2
else if (i==82)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 3
else if (i==83)		{	low = 0.00000001;			high = 1;	}   //META 3 SUB 4

//-----OBSERVATIONAL-----
//-----META 4-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==84)		{	low = 0;			high = 5;       } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==85)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0.0001-0.9

//STARTING          {   low = -11.5;		high = -4.6;	}   //INITR         //0.00001-0.01
else if (i==86)		{	low = -11.5;		high = -4.6;    } 	//INITR         //0.00001-0.01

//-----META 5-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==87)		{	low = 0;			high = 5;       } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==88)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0-0.9

//-----META 6-----
//STARTING          {   low = 0;			high = 5;	    }   //INITS         //1-148.4
else if (i==89)		{	low = 0;			high = 5;     } 	//INITS         //1-148.4

//STARTING          {   low = -9.2;			high = -0.1;	}   //INITV         //0.0001-0.9
else if (i==90)		{	low = -9.2;			high = -0.1;    } 	//INITV         //0.0001-0.9

//STARTING          {   low = -11.5;		high = -4.6;	}   //INITR         //0.00001-0.01
else if (i==91)		{	low = -11.5;		high = -4.6;	} 	//INITR         //0.00001-0.01

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;
}
}
