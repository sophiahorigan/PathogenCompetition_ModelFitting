double ls_bound(int model, int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;
//LOG SCALE! 

if(model==1){  //L POP, C NA, R POP                                                                 //***fitting
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

    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}

}
// ------------------------------------------------------------------------------------ //

double mcmc_bound(int model, int i,int j)	
{
double low;
double high;

if(model==1){       //at least as wide or wider than ls bounds
    if (i==0)			{	low = 0.00000001;	    high = 75;      }	//INITS 
    else if (i==1)		{	low = 0.00000001;       high = 0.36;	}	//INITR POP
    else if (i==2)		{	low = 0.00000001;		high = 10;		}	//R STOCH
    else if (i==3)		{	low = 0.00000001;		high = 10;		}	//F STOCH
    else if (i==4)		{	low = 0.00000001;	    high = 100;	    } 	//l_a_pop
    else if (i==5)		{	low = 0.00000001;		high = 1;		}	//l_m_pop
}
if(model==21){      //need to update to not include fixed params
    if (i==0)			{	low = 1;			high = 50;      }	//initS 
    //initR sub
    else if (i==1)		{	low = 0;			high = 0.6;		}	//initR 1.1
    else if (i==2)		{	low = 0;			high = 0.6;		}	//initR 2.1
    else if (i==3)		{	low = 0;			high = 0.6;		}	//initR 2.2
    else if (i==4)		{	low = 0;			high = 0.6;		}	//initR 2.3
    else if (i==5)		{	low = 0;			high = 0.6;		}	//initR 2.4
    else if (i==6)		{	low = 0;			high = 0.6;		}	//initR 3.1
    else if (i==7)		{	low = 0;			high = 0.6;		}	//initR 3.2
    else if (i==8)		{	low = 0;			high = 0.6;		}	//initR 3.3
    else if (i==9)		{	low = 0;			high = 0.6;		}	//initR 3.4
    //VIRUS PARAMS //WHAT SHOULD THESE BE??
    else if (i==10)		{	low = 0.001;		high = 35;		} 	//virus decay rate
    else if (i==11) 	{	low = 0.01;			high = 20;		}	//heterogeneity //too high was 2.7
    else if (i==12)	    {	low = 0.01; 		high = 35;	    }	//virus transmission
    //FUNGUS PARAM
    else if (i==13) 	{	low = 3.05902321e-10;		high = 0.1; 	}	//fungus transmission
    //STOCHASTICITY
    else if (i==14)		{	low = 0;			high = 20;		}	//Rsd_exp 
    else if (i==15)		{	low = 0;			high = 20;		}	//Fsd_exp 
    //pop c disp
    else if (i==16)		{	low = 0;			high = 1202604;	} 	//c_a_pop
    else if (i==17)		{	low = 0;			high = 1;		}	//c_m_pop
    //pop l disp
    else if (i==18)		{	low = 0;			high = 2000;	} 	//l_a_pop
    else if (i==19)		{	low = 0;			high = 1;		}	//l_m_pop
}
if(model==45){
    if (i==0)			{	low = 0;			high = 50; 	    }	//initS //1-35
    //1
    else if (i==1)		{	low = 0;			high = 0.6;		}	//initR meta 1 sub1 //0-0.04
    //2
    else if (i==2)		{	low = 0;			high = 0.6;		}	//initR meta 2 sub1 //0-0.04
    else if (i==3)		{	low = 0;			high = 0.6;		}	//initR meta 2 sub2 //0-0.04
    else if (i==4)		{	low = 0;			high = 0.6;		}	//initR meta 2 sub3 //0-0.04
    else if (i==5)		{	low = 0;			high = 0.6;		}	//initR meta 2 sub4 //0-0.04
    //3
    else if (i==6)		{	low = 0;			high = 0.6;		}	//initR meta 3 sub1 //0-0.04
    else if (i==7)		{	low = 0;			high = 0.6;		}	//initR meta 3 sub2 //0-0.04
    else if (i==8)		{	low = 0;			high = 0.6;		}	//initR meta 3 sub3 //0-0.04
    else if (i==9)		{	low = 0;			high = 0.6;		}	//initR meta 3 sub4 //0-0.04
    //VIRUS PARAMS
    else if (i==10)		{	low = 0.001;		high = 35;		} 	//virus decay muV //0.01 - 20
    else if (i==11)		{	low = 0.01;			high = 20;		}	//virus heterogeneity CV //0.01 - 6.25
    else if (i==12)		{	low = 0.01; 		high = 35;	    }  //virus transmission nuV //0.01 - 20 
    //FUNGUS PARAMS
    else if (i==13)		{	low = 3.05902321e-10;		high = 0.1; 	} 	//fungus transmission //0.00001 - 0.016
    //STOCHASTICITY
    else if (i==14)		{	low = 0;			high = 20;		}	//Rsd	//0-20
    else if (i==15)		{	low = 0;			high = 20;		}	//Fsd   //0-20
    //CONIDIA DISPERSAL
    else if (i==16)		{	low = 0;			high = 1202604;	}   // c_a_sub //meta1
    else if (i==17)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==18)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==19)		{	low = 0;			high = 1202604;	}  // c_a_sub

    else if (i==20)		{	low = 0;			high = 1202604;	}  // c_a_sub //meta2
    else if (i==21)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==22)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==23)		{	low = 0;			high = 1202604;	}  // c_a_sub

    else if (i==24)		{	low = 0;			high = 1202604;	}  // c_a_sub //meta3
    else if (i==25)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==26)		{	low = 0;			high = 1202604;	}  // c_a_sub
    else if (i==27)		{	low = 0;			high = 1202604;	}   // c_a_sub
    //non-log
    else if (i==28)		{	low = 0;			high = 1;		}	 //c_m_sub //meta1
    else if (i==29)		{	low = 0;			high = 1;		}	//c_m_sub
    else if (i==30)		{	low = 0;			high = 1;		}	 //c_m_sub
    else if (i==31)		{	low = 0;			high = 1;		}	 //c_m_sub

    else if (i==32)		{	low = 0;			high = 1;		}	 //c_m_sub //meta2
    else if (i==33)		{	low = 0;			high = 1;		}	 //c_m_sub
    else if (i==34)		{	low = 0;			high = 1;		}	//c_m_sub
    else if (i==35)		{	low = 0;			high = 1;		}	//c_m_sub

    else if (i==36)		{	low = 0;			high = 1;		}	 //c_m_sub //meta3
    else if (i==37)		{	low = 0;			high = 1;		}	 //c_m_sub
    else if (i==38)		{	low = 0;			high = 1;		}	 //c_m_sub
    else if (i==39)		{	low = 0;			high = 1;		}	 //c_m_sub
    //LARVAL DISPERSAL
    else if (i==40)		{	low = 0;			high = 1202604;	}  // l_a_sub //meta1
    else if (i==41)		{	low = 0;			high = 1202604;	}  // l_a_sub
    else if (i==42)		{	low = 0;			high = 1202604;	}  // l_a_sub
    else if (i==43)		{	low = 0;			high = 1202604;	}  // l_a_sub

    else if (i==44)		{	low = 0;			high = 1202604;	}  // l_a_sub //meta2
    else if (i==45)		{	low = 0;			high = 1202604;	} // l_a_sub
    else if (i==46)		{	low = 0;			high = 1202604;	}  // l_a_sub
    else if (i==47)		{	low = 0;			high = 1202604;	}  // l_a_sub

    else if (i==48)		{	low = 0;			high = 1202604;	}  // l_a_sub //meta3
    else if (i==49)		{	low = 0;			high = 1202604;	}  // l_a_sub
    else if (i==50)		{	low = 0;			high = 1202604;	}  // l_a_sub
    else if (i==51)		{	low = 0;			high = 1202604;	}  // l_a_sub
    //non-log
    else if (i==52)		{	low = 0;			high = 1;		}	//l_m_sub //meta1
    else if (i==53)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==54)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==55)		{	low = 0;			high = 1;		}	 //l_m_sub

    else if (i==56)		{	low = 0;			high = 1;		}	 //l_m_sub //meta2
    else if (i==57)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==58)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==59)		{	low = 0;			high = 1;		}	//l_m_sub

    else if (i==60)		{	low = 0;			high = 1;		}	 //l_m_sub //meta3
    else if (i==61)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==62)		{	low = 0;			high = 1;		}	 //l_m_sub
    else if (i==63)		{	low = 0;			high = 1;		}	 //l_m_sub
	}
    
if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;
}
}
