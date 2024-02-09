double ls_bound(int model, int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//SAME FOR ALL MODELS - CURRENTLY USING

//-----INITS-------
//STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
if (i==0)			{   low = -15;         high = 4.3;      }	//POP           //0.01-75     //****

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
else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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

//MODEL SPECIFIC - NOT CURRENTLY USING
/*
if(model==1){  //L POP, C NA, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -20;        high = 0;      }	//POP           //0.000001-1  //****
    else if (i==2)		{   low = -20;        high = 0;      }	//META 1        //0.000001-1
    else if (i==3)		{   low = -20;        high = 0;      }	//META 2        //0.000001-1
    else if (i==4)		{   low = -20;        high = 0;      }	//META 3        //0.000001-1
    else if (i==5)		{   low = -20;        high = 0;      }	//META 1 SUB 1  //0.000001-1
    else if (i==6)		{   low = -20;        high = 0;      }	//META 2 SUB 1  //0.000001-1
    else if (i==7)		{   low = -20;        high = 0;      }	//META 2 SUB 2  //0.000001-1
    else if (i==8)		{   low = -20;        high = 0;      }	//META 2 SUB 3  //0.000001-1
    else if (i==9)		{   low = -20;        high = 0;      }	//META 2 SUB 4  //0.000001-1
    else if (i==10)		{   low = -20;        high = 0;      }	//META 3 SUB 1  //0.000001-1
    else if (i==11)		{   low = -20;        high = 0;      }	//META 3 SUB 2  //0.000001-1
    else if (i==12)		{   low = -20;        high = 0;      }	//META 3 SUB 3  //0.000001-1
    else if (i==13)		{	low = -20;		  high = 0;	    }	//META 3 SUB 4  //0.000001-1

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -6.9;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -6.9;		    high = 1;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -6.9;		    high = 1;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -6.9;		    high = 1;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -6.9;		    high = 1;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -6.9;		    high = 1;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -6.9;		    high = 1;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -6.9;		    high = 1;     }  //META 2        //0.00001-100
    else if (i==55)		{	low = -6.9;		    high = 1;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -6.9;		    high = 1;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -6.9;		    high = 1;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -6.9;		    high = 1;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==2){  //L POP, C NA, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==3){  //L POP, C NA, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -6.5;         high = -5.8;    }	//META 1 SUB 1  //0.000001-0.36     //****
    else if (i==6)		{   low = -6.5;         high = -5.8;    }	//META 2 SUB 1  //0.000001-0.36     //****
    else if (i==7)		{   low = -6.5;         high = -5.8;    }	//META 2 SUB 2  //0.000001-0.36     //****
    else if (i==8)		{   low = -6.5;         high = -5.8;    }	//META 2 SUB 3  //0.000001-0.36     //****
    else if (i==9)		{   low = -6.5;         high = -5.8;    }	//META 2 SUB 4  //0.000001-0.36     //****
    else if (i==10)		{   low = -6.5;         high = -5.8;    }	//META 3 SUB 1  //0.000001-0.36     //****
    else if (i==11)		{   low = -6.5;         high = -5.8;    }	//META 3 SUB 2  //0.000001-0.36     //****
    else if (i==12)		{   low = -6.5;         high = -5.8;    }	//META 3 SUB 3  //0.000001-0.36     //****
    else if (i==13)		{   low = -6.5;         high = -5.8;    }	//META 3 SUB 4  //0.000001-0.36     //****

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==4){  //L META, C NA, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==5){  //L META, C NA, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==6){  //L META, C NA, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==7){  //L SUB, C NA, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==8){  //L SUB, C NA, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==9){  //L SUB, C NA, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==10){  //L NA, C POP, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    ///-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==11){  //L NA, C POP, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==12){  //L NA, C POP, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==13){  //L NA, C META, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==14){  //L NA, C META, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==15){  //L NA, C META, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==16){  //L NA, C SUB, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==17){  //L NA, C SUB, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==18){  //L NA, C SUB, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==19){  //L POP, C POP, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if (model==20){ //L POP, C POP, R META
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
     if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.13-7.38   

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
    //-----VIRUS DECAY muV------
    //STARTING          {   low = -9;           high = 2.3;     }                   //0.0001-10
    else if (i==14)		{   low = -9;           high = 2.3;     }	//POP           //0.01-7.38     

    //-----VIRUS HETERO CV-----
    //STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
    else if (i==15)		{   low = -9;           high = 3;       }	//POP           //0.01-6.25   

    //-----VIRUS TRANS nuV----
    //STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
    else if (i==16)		{   low = -9;           high = 3;       }   //POP           //0.01-20       

    //-----FUNGUS TRANS nuF-----
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36
    else if (i==17)		{   low = -11.5;        high = -1;      }   //POP           //0.00004-0.36  

    //-----R STOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==18)		{   low = -11.5;        high = 3;       }	//POP	        //0.01-2.7     

    //-----F STOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.01-20       

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100  
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.000001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.000001;			high = 1;	}   //POP                         
    else if (i==69)		{	low = 0.000001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.000001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.000001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 4

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
}

if (model==21){ //L POP, C POP, R SUB
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
     if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.13-7.38   

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
    //-----VIRUS DECAY muV------
    //STARTING          {   low = -9;           high = 2.3;     }                   //0.0001-10
    else if (i==14)		{   low = -9;           high = 2.3;     }	//POP           //0.01-7.38     

    //-----VIRUS HETERO CV-----
    //STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
    else if (i==15)		{   low = -9;           high = 3;       }	//POP           //0.01-6.25   

    //-----VIRUS TRANS nuV----
    //STARTING          {   low = -9;           high = 3;       }                   //0.0001-20
    else if (i==16)		{   low = -9;           high = 3;       }   //POP           //0.01-20       

    //-----FUNGUS TRANS nuF-----
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36
    else if (i==17)		{   low = -11.5;        high = -1;      }   //POP           //0.00004-0.36  

    //-----R STOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==18)		{   low = -11.5;        high = 3;       }	//POP	        //0.01-2.7     

    //-----F STOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.01-20       

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100  
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.000001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.000001;			high = 1;	}   //POP                         
    else if (i==69)		{	low = 0.000001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.000001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.000001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.000001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.000001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.000001;			high = 1;	}   //META 3 SUB 4

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
}
   
if(model==22){  //L POP, C META, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==23){  //L POP, C META, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    ///-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==24){  //L POP, C META, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==25){  //L POP, C SUB, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==26){  //L POP, C SUB, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==27){  //L POP, C SUB, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==28){  //L META, C POP, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==29){  //L META, C POP, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==30){  //L META, C POP, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==31){  //L META, C META, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

   //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==32){  //L META, C META, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==33){  //L META, C META, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==34){  //L META, C SUB, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==35){  //L META, C SUB, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==36){  //L META, C SUB, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==37){  //L SUB, C POP, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==38){  //L SUB, C POP, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==39){  //L SUB, C POP, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==40){  //L SUB, C META, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==41){  //L SUB, C META, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36
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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==42){  //L SUB, C META, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==43){  //L SUB, C SUB, R POP                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==44){  //L SUB, C SUB, R META                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

if(model==45){  //L SUB, C SUB, R SUB                                                                 //***fitting
    //-----INITS-------
    //STARTING          {   low = -4.5;         high = 4.3      }                   //0.01-75
    if (i==0)			{   low = -4.5;         high = 4.3;      }	//POP           //0.01-75     //****

    //-----INITR------
    //STARTING          {   low = -11.5;        high = -1;      }                   //0.00001-0.36  
    else if (i==1)		{   low = -13.8;        high = -1;      }	//POP           //0.000001-0.36  //****
    else if (i==2)		{   low = -13.8;        high = -1;      }	//META 1        //0.000001-0.36
    else if (i==3)		{   low = -13.8;        high = -1;      }	//META 2        //0.000001-0.36
    else if (i==4)		{   low = -13.8;        high = -1;      }	//META 3        //0.000001-0.36
    else if (i==5)		{   low = -13.8;        high = -1;      }	//META 1 SUB 1  //0.000001-0.36
    else if (i==6)		{   low = -13.8;        high = -1;      }	//META 2 SUB 1  //0.000001-0.36
    else if (i==7)		{   low = -13.8;        high = -1;      }	//META 2 SUB 2  //0.000001-0.36
    else if (i==8)		{   low = -13.8;        high = -1;      }	//META 2 SUB 3  //0.000001-0.36
    else if (i==9)		{   low = -13.8;        high = -1;      }	//META 2 SUB 4  //0.000001-0.36
    else if (i==10)		{   low = -13.8;        high = -1;      }	//META 3 SUB 1  //0.000001-0.36
    else if (i==11)		{   low = -13.8;        high = -1;      }	//META 3 SUB 2  //0.000001-0.36
    else if (i==12)		{   low = -13.8;        high = -1;      }	//META 3 SUB 3  //0.000001-0.36
    else if (i==13)		{	low = -13.8;		high = -1;	    }	//META 3 SUB 4  //0.000001-0.36

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
    else if (i==18)		{   low = -11.5;        high = 2.3;       }	//POP	        //0.00001-10    //****

    //-----FSTOCH-----
    //STARTING          {   low = -11.5;        high = 3;       }                   //0.00001-20
    else if (i==19)		{   low = -11.5;        high = 3;       }	//POP           //0.00001-20    //****

    //-----CONIDIA 1/AVG DIST DISP c_a-----
    //STARTING          {   low = -11.5;        high = 4.6;     }                   //0.00001-100
    else if (i==20)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100
    else if (i==21)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==22)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==23)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==24)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==25)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==26)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==27)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==28)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==29)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==30)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==31)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==32)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==33)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==34)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==35)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

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
    else if (i==52)		{	low = -11.5;		high = 4.6;     }   //POP           //0.00001-100   //****
    else if (i==53)		{	low = -11.5;		high = 4.6;     }   //META 1        //0.00001-100
    else if (i==54)		{	low = -11.5;		high = 4.6;     }   //META 2        //0.00001-100
    else if (i==55)		{	low = -11.5;		high = 4.6;     }   //META 3        //0.00001-100
    else if (i==56)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 1  //0.00001-100
    else if (i==57)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 2  //0.00001-100
    else if (i==58)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 3  //0.00001-100
    else if (i==59)		{	low = -11.5;		high = 4.6;     }   //META 1 SUB 4  //0.00001-100
    else if (i==60)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 1  //0.00001-100
    else if (i==61)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 2  //0.00001-100
    else if (i==62)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 3  //0.00001-100
    else if (i==63)		{	low = -11.5;		high = 4.6;     }   //META 2 SUB 4  //0.00001-100
    else if (i==64)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 1  //0.00001-100
    else if (i==65)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 2  //0.00001-100
    else if (i==66)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 3  //0.00001-100
    else if (i==67)		{	low = -11.5;		high = 4.6;     }   //META 3 SUB 4  //0.00001-100

    //-----LARVAE FRAC SUCCESSFUL DISP l_m----- 
    //STARTING          {   low = 0.00001;			high = 1;	}                   //non-log
    else if (i==68)		{	low = 0.00001;			high = 1;	}   //POP                           //****
    else if (i==69)		{	low = 0.00001;			high = 1;	}   //META 1
    else if (i==70)		{	low = 0.00001;			high = 1;	}   //META 2
    else if (i==71)		{	low = 0.00001;			high = 1;	}   //META 3
    else if (i==72)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 1
    else if (i==73)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 2
    else if (i==74)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 3
    else if (i==75)		{	low = 0.00001;			high = 1;	}   //META 1 SUB 4
    else if (i==76)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 1
    else if (i==77)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 2 
    else if (i==78)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 3
    else if (i==79)		{	low = 0.00001;			high = 1;	}   //META 2 SUB 4
    else if (i==80)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 1
    else if (i==81)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 2
    else if (i==82)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 3
    else if (i==83)		{	low = 0.00001;			high = 1;	}   //META 3 SUB 4

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
}

*/
    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}

}
// ------------------------------------------------------------------------------------ //

double mcmc_bound(int model, int i,int j)	
{
double low;
double high;

if(model==1){       //R POP, C NA, L POP
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR POP
    else if (i==2)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==3)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==4)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_pop
    else if (i==5)		{	low = 0.00000001;		high = 1;		}	//l_m_pop
}
if(model==2){      //R META, C NA, L POP
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 1
    else if (i==2)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 2
    else if (i==3)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 3
    else if (i==4)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==5)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==6)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_pop
    else if (i==7)		{	low = 0.00000001;		high = 1;		}	//l_m_pop
}
if(model==4){      //R POP, C NA, L META
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR POP
    else if (i==2)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==3)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==4)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 1
    else if (i==5)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 2
    else if (i==6)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 3
    else if (i==7)		{	low = 0.00000001;		high = 1;		}	//l_m_META 1
    else if (i==8)		{	low = 0.00000001;		high = 1;		}	//l_m_META 2
    else if (i==9)		{	low = 0.00000001;		high = 1;		}	//l_m_META 3
}
if(model==22){      //R POP, C META, L POP
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR POP
    else if (i==2)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==3)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==4)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 1
    else if (i==5)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 2
    else if (i==6)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 3
    else if (i==7)		{	low = 0.00000001;		high = 1;		}	//C_m_META 1
    else if (i==8)		{	low = 0.00000001;		high = 1;		}	//C_m_META 2
    else if (i==9)		{	low = 0.00000001;		high = 1;		}	//C_m_META 3
    else if (i==10)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_pop
    else if (i==11)		{	low = 0.00000001;		high = 1;		}	//l_m_pop
}
if(model==28){      //R POP, C POP, L META
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR POP
    else if (i==2)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==3)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==4)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_pop
    else if (i==5)		{	low = 0.00000001;		high = 1;		}	//C_m_pop
    else if (i==6)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 1
    else if (i==7)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 2
    else if (i==8)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 3
    else if (i==9)		{	low = 0.00000001;		high = 1;		}	//l_m_META 1
    else if (i==10)		{	low = 0.00000001;		high = 1;		}	//l_m_META 2
    else if (i==11)		{	low = 0.00000001;		high = 1;		}	//l_m_META 3
}
if(model==32){      //R META, C META, L META
    if (i==0)			{	low = 0.00000001;	    high = 200;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 1
    else if (i==2)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 2
    else if (i==3)		{	low = 0.00000001;       high = 0.36;	}	//INITR META 3
    else if (i==4)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==5)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==6)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 1
    else if (i==7)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 2
    else if (i==8)		{	low = 0.00000001;	    high = 100;	    } 	//C_a_META 3
    else if (i==9)		{	low = 0.00000001;		high = 1;		}	//C_m_META 1
    else if (i==10)		{	low = 0.00000001;		high = 1;		}	//C_m_META 2
    else if (i==11)		{	low = 0.00000001;		high = 1;		}	//C_m_META 3
    else if (i==12)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 1
    else if (i==13)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 2
    else if (i==14)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_META 3
    else if (i==15)		{	low = 0.00000001;		high = 1;		}	//l_m_META 1
    else if (i==16)		{	low = 0.00000001;		high = 1;		}	//l_m_META 2
    else if (i==17)		{	low = 0.00000001;		high = 1;		}	//l_m_META 3
}

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;
}
}
