double ls_bound(int model, int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;
//EXPAND LOG SCALE BOUNDS BASED ON LOG LINESEARCH

if (model==21){
    if (i==0)			{	low = 0;			high = 2;	    }	//initS //1-35

    //INITR
    //pop
    else if (i==1)		{	low = -11.5;		high = -3.21;	}	//initR POP //0-0.04
    //meta
    else if (i==2)		{	low = -11.5;		high = -3.21;	}	//initR META 1 //0-0.04
    else if (i==3)		{	low = -11.5;		high = -3.21;	}	//initR META 2 //0-0.04
    else if (i==4)		{	low = -11.5;		high = -3.21;	}	//initR META 3 //0-0.04
    //sub
    //1
    else if (i==5)		{	low = -11.5;		high = -4;	}	//initR meta 1 sub1 //0-0.04
    //2
    else if (i==6)		{	low = -5;		    high = -1;	}	//initR meta 2 sub1 //0-0.04
    else if (i==7)		{	low = -11.5;		high = -3.21;	}	//initR meta 2 sub2 //0-0.04
    else if (i==8)		{	low = -6;   		high = -1;	}	//initR meta 2 sub3 //0-0.04
    else if (i==9)		{	low = -9;		    high = -3.21;	}	//initR meta 2 sub4 //0-0.04
    //3
    else if (i==10)		{	low = -4.5;		    high = -1;	}	//initR meta 3 sub1 //0-0.04
    else if (i==11)		{	low = -8;	    	high = -3.21;	}	//initR meta 3 sub2 //0-0.04
    else if (i==12)		{	low = -5;	    	high = -3.21;	}	//initR meta 3 sub3 //0-0.04
    else if (i==13)		{	low = -11.5;		high = -1;	}	//initR meta 3 sub4 //0-0.04
    //VIRUS PARAMS
    else if (i==14)		{	low = -1.5;		    high = 3;	}	//virus decay muV //0.01 - 20
    else if (i==15)		{	low = -4.6;			high = 2.3;		}	//virus heterogeneity CV //0.01 - 6.25
    else if (i==16)		{	low = -2.5;			high = 3;	}  //virus transmission nuV //0.01 - 20 
    //FUNGUS PARAMS
    else if (i==17)		{	low = -15;		high = -4.13;	} 	//fungus transmission //0.00001 - 0.016
    //STOCHASTICITY
    else if (i==18)		{	low = -2;			high = 1;		}	//Rsd	//0-20
    else if (i==19)		{	low = -7;			high = 2;		}	//Fsd   //0-20
    //CONIDIA DISPERSAL
    else if (i==20)		{	low = 3;			high = 14;	    }  // c_a_pop //0 - 1096

    else if (i==21)		{	low = -8.5;			high = 7;	    }  // c_a_meta1 //0-1096
    else if (i==22)		{	low = -8.5;			high = 7;       }  // c_a_meta2
    else if (i==23)		{	low = -8.5;			high = 7;       }  // c_a_meta3

    else if (i==24)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta1
    else if (i==25)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==26)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==27)		{	low = -8.5;			high = 7;	    }  // c_a_sub

    else if (i==28)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta2
    else if (i==29)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==30)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==31)		{	low = -8.5;			high = 7;	    }  // c_a_sub

    else if (i==32)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta3
    else if (i==33)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==34)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==35)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    //non-log
    else if (i==36)		{	low = 0.00001;			high = 1;	} //c_m_pop //0 - 1

    else if (i==37)		{	low = 0.00001;			high = 1;	} //c_m_meta1
    else if (i==38)		{	low = 0.00001;			high = 1;	} //c_m_meta2
    else if (i==39)		{	low = 0.00001;			high = 1;	} //c_m_meta3

    else if (i==40)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta1
    else if (i==41)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==42)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==43)		{	low = 0.000001;			high = 1;	} //c_m_sub

    else if (i==44)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta2
    else if (i==45)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==46)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==47)		{	low = 0.000001;			high = 1;	} //c_m_sub

    else if (i==48)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta3
    else if (i==49)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==50)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==51)		{	low = 0.000001;			high = 1;	} //c_m_sub
    //LARVAL DISPERSAL
    else if (i==52)		{	low = -2;			high = 3;	    }  // l_a_pop 0-100

    else if (i==53)		{	low = -8.5;			high = 7;    }  // l_a_meta1
    else if (i==54)		{	low = -8.5;			high = 7;	    }  // l_a_meta2
    else if (i==55)		{	low = -8.5;			high = 7;	    }  // l_a_meta3

    else if (i==56)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta1
    else if (i==57)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==58)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==59)		{	low = -8.5;			high = 7;	    }  // l_a_sub

    else if (i==60)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta2
    else if (i==61)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==62)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==63)		{	low = -8.5;			high = 7;	    }  // l_a_sub

    else if (i==64)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta3
    else if (i==65)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==66)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==67)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    //non-log
    else if (i==68)		{	low = 0.000001;			high = 0.8; } //l_m_pop *

    else if (i==69)		{	low = 0.000001;			high = 1; } //l_m_meta1
    else if (i==70)		{	low = 0.000001;			high = 1; } //l_m_meta2
    else if (i==71)		{	low = 0.000001;			high = 1; } //l_m_meta3

    else if (i==72)		{	low = 0.000001;			high = 1; } //l_m_sub //meta1
    else if (i==73)		{	low = 0.000001;			high = 1; } //l_m_sub
    else if (i==74)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==75)		{	low = 0.000001;			high = 1;	} //l_m_sub

    else if (i==76)		{	low = 0.000001;			high = 1;	} //l_m_sub //meta2
    else if (i==77)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==78)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==79)		{	low = 0.000001;			high = 1;	} //l_m_sub

    else if (i==80)		{	low = 0.000001;			high = 1;	} //l_m_sub //meta3
    else if (i==81)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==82)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==83)		{	low = 0.000001;			high = 1;	} //l_m_sub

    //OBS
    //4
    else if (i==84)		{	low = 0;			high = 5;       } 	//initS //1-148
    else if (i==85)		{	low = -9.2;			high = -0.1;    } 	//initV  //0 - .9
    else if (i==86)		{	low = -11.5;		high = -4.6;    } 	//initR //0-0.01
    //5
    else if (i==87)		{	low = 0;			high = 5;       } 	//initS //1-148
    else if (i==88)		{	low = -9.2;			high = -0.7;    } 	//initV  //0 - .5
    //6
    else if (i==89)		{	low = 0;			high = 5.5;     } 	//initS //1-250
    else if (i==90)		{	low = -9.2;			high = -0.1;    } 	//initV  //0 - .9
    else if (i==91)		{	low = -11.5;		high = -4.6;	} 	//initR //0-0.01

    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}
}
if(model==45){
    if (i==0)			{	low = 0;			high = 2;	    }	//initS //1-35

    //INITR
    //pop
    else if (i==1)		{	low = -11.5;		high = -3.21;	}	//initR POP //0-0.04
    //meta
    else if (i==2)		{	low = -11.5;		high = -3.21;	}	//initR META 1 //0-0.04
    else if (i==3)		{	low = -11.5;		high = -3.21;	}	//initR META 2 //0-0.04
    else if (i==4)		{	low = -11.5;		high = -3.21;	}	//initR META 3 //0-0.04
    //sub
    //1
    else if (i==5)		{	low = -11.5;		high = -3.21;	}	//initR meta 1 sub1 //0-0.04
    //2
    else if (i==6)		{	low = -11.5;		high = -3.21;	}	//initR meta 2 sub1 //0-0.04
    else if (i==7)		{	low = -11.5;		high = -3.21;	}	//initR meta 2 sub2 //0-0.04
    else if (i==8)		{	low = -11.5;		high = -3.21;	}	//initR meta 2 sub3 //0-0.04
    else if (i==9)		{	low = -11.5;		high = -3.21;	}	//initR meta 2 sub4 //0-0.04
    //3
    else if (i==10)		{	low = -11.5;		high = -3.21;	}	//initR meta 3 sub1 //0-0.04
    else if (i==11)		{	low = -11.5;		high = -3.21;	}	//initR meta 3 sub2 //0-0.04
    else if (i==12)		{	low = -11.5;		high = -3.21;	}	//initR meta 3 sub3 //0-0.04
    else if (i==13)		{	low = -11.5;		high = -3.21;	}	//initR meta 3 sub4 //0-0.04
    //VIRUS PARAMS
    else if (i==14)		{	low = -1.5;		    high = 3;	}	//virus decay muV //0.01 - 20
    else if (i==15)		{	low = -4.6;			high = 2.3;		}	//virus heterogeneity CV //0.01 - 6.25
    else if (i==16)		{	low = -2.5;			high = 3;	}  //virus transmission nuV //0.01 - 20 
    //FUNGUS PARAMS
    else if (i==17)		{	low = -15;		high = -4.13;	} 	//fungus transmission //0.00001 - 0.016
    //STOCHASTICITY
    else if (i==18)		{	low = -2;			high = 1;		}	//Rsd	//0-20
    else if (i==19)		{	low = -7;			high = 2;		}	//Fsd   //0-20
    //CONIDIA DISPERSAL
    else if (i==20)		{	low = -8.5;			high = 7;	    }  // c_a_pop //0 - 1096

    else if (i==21)		{	low = -8.5;			high = 7;	    }  // c_a_meta1 //0-1096
    else if (i==22)		{	low = -8.5;			high = 7;	    }  // c_a_meta2
    else if (i==23)		{	low = -8.5;			high = 7;	    }  // c_a_meta3

    else if (i==24)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta1
    else if (i==25)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==26)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==27)		{	low = -8.5;			high = 7;	    }  // c_a_sub

    else if (i==28)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta2
    else if (i==29)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==30)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==31)		{	low = -8.5;			high = 7;	    }  // c_a_sub

    else if (i==32)		{	low = -8.5;			high = 7;	    }  // c_a_sub //meta3
    else if (i==33)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==34)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    else if (i==35)		{	low = -8.5;			high = 7;	    }  // c_a_sub
    //non-log
    else if (i==36)		{	low = 0.000001;			high = 1;	} //c_m_pop //0 - 1

    else if (i==37)		{	low = 0.000001;			high = 1;	} //c_m_meta1
    else if (i==38)		{	low = 0.000001;			high = 1;	} //c_m_meta2
    else if (i==39)		{	low = 0.000001;			high = 1;	} //c_m_meta3

    else if (i==40)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta1
    else if (i==41)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==42)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==43)		{	low = 0.000001;			high = 1;	} //c_m_sub

    else if (i==44)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta2
    else if (i==45)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==46)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==47)		{	low = 0.000001;			high = 1;	} //c_m_sub

    else if (i==48)		{	low = 0.000001;			high = 1;	} //c_m_sub //meta3
    else if (i==49)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==50)		{	low = 0.000001;			high = 1;	} //c_m_sub
    else if (i==51)		{	low = 0.000001;			high = 1;	} //c_m_sub
    //LARVAL DISPERSAL
    else if (i==52)		{	low = -8.5;			high = 7;       }  // l_a_pop 0-100

    else if (i==53)		{	low = -8.5;			high = 7;       }  // l_a_meta1
    else if (i==54)		{	low = -8.5;			high = 7;	    }  // l_a_meta2
    else if (i==55)		{	low = -8.5;			high = 7;	    }  // l_a_meta3

    else if (i==56)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta1
    else if (i==57)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==58)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==59)		{	low = -8.5;			high = 7;	    }  // l_a_sub

    else if (i==60)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta2
    else if (i==61)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==62)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==63)		{	low = -8.5;			high = 7;	    }  // l_a_sub

    else if (i==64)		{	low = -8.5;			high = 7;	    }  // l_a_sub //meta3
    else if (i==65)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==66)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    else if (i==67)		{	low = -8.5;			high = 7;	    }  // l_a_sub
    //non-log
    else if (i==68)		{	low = 0.000001;			high = 1; } //l_m_pop *

    else if (i==69)		{	low = 0.000001;			high = 1; } //l_m_meta1
    else if (i==70)		{	low = 0.000001;			high = 1; } //l_m_meta2
    else if (i==71)		{	low = 0.000001;			high = 1; } //l_m_meta3

    else if (i==72)		{	low = 0.000001;			high = 1; } //l_m_sub //meta1
    else if (i==73)		{	low = 0.000001;			high = 1; } //l_m_sub
    else if (i==74)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==75)		{	low = 0.000001;			high = 1;	} //l_m_sub

    else if (i==76)		{	low = 0.000001;			high = 1;	} //l_m_sub //meta2
    else if (i==77)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==78)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==79)		{	low = 0.000001;			high = 1;	} //l_m_sub

    else if (i==80)		{	low = 0.000001;			high = 1;	} //l_m_sub //meta3
    else if (i==81)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==82)		{	low = 0.000001;			high = 1;	} //l_m_sub
    else if (i==83)		{	low = 0.000001;			high = 1;	} //l_m_sub

    //OBS
    //4
    else if (i==84)		{	low = 0;			high = 5;       } 	//initS //1-148
    else if (i==85)		{	low = -9.2;			high = -0.1;    } 	//initV  //0 - .9
    else if (i==86)		{	low = -11.5;		high = -4.6;    } 	//initR //0-0.01
    //5
    else if (i==87)		{	low = 0;			high = 5;       } 	//initS //1-148
    else if (i==88)		{	low = -9.2;			high = -0.7;    } 	//initV  //0 - .5
    //6
    else if (i==89)		{	low = 0;			high = 5.5;     } 	//initS //1-250
    else if (i==90)		{	low = -9.2;			high = -0.1;    } 	//initV  //0 - .9
    else if (i==91)		{	low = -11.5;		high = -4.6;	} 	//initR //0-0.01

    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PARAMETERS!!\n");	return 0;	}
}

}
// ------------------------------------------------------------------------------------ //
//DO I NEED THIS?? CAN JUST USE ONE SET OF BOUNDS FOR ALL PARAMS ACROSS ALL FITTING
double prior_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;
//MAKE IN LOG SCALE? (for all params except m) //NOT CURRENTLY USING
//EXPAND! 

//metapopulation one
if (i==0)			{	low = 1;			high = 200;    }	//initS 
//INIT R
//pop
else if (i==1)		{	low = 0;			high = 0.04;		}	//initR 
//meta
else if (i==2)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==3)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==4)		{	low = 0;			high = 0.04;		}	//initR 
//sub
else if (i==5)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==6)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==7)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==8)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==9)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==10)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==11)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==12)		{	low = 0;			high = 0.04;		}	//initR 
else if (i==13)		{	low = 0;			high = 0.04;		}	//initR 

//VIRUS PARAMS
else if (i==14)		{	low = 0.01;			high = 20;		} 	//virus decay rate
else if (i==15) 	{	low = 0.01;			high = 10;		}	//heterogeneity
else if (i==16)	    {	low = 0.01; 		high = 4;	    }	//virus transmission
//FUNGUS PARAM
else if (i==17) 	{	low = 0.00001;		high = 0.02;	}	//fungus transmission
//STOCHASTICITY
else if (i==18)		{	low = 0;			high = 20;		}	//Rsd_exp
else if (i==19)		{	low = 0;			high = 20;		}	//Fsd_exp
//CONIDIA DISPERSAL
else if (i==20)		{	low = 0;			high = 100;	    } 	//c_a_pop

else if (i==21)		{	low = 0;			high = 1096;	    } 	//c_a_meta
else if (i==22)		{	low = 0;			high = 1096;	    } 	//c_a_meta
else if (i==23)		{	low = 0;			high = 1096;	    } 	//c_a_meta

else if (i==24)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==25)		{	low = 0;			high = 1096;	    }  	//c_a_sub
else if (i==26)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==27)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==28)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==29)		{	low = 0;			high = 1096; 	    } 	//c_a_sub
else if (i==30)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==31)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==32)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==33)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==34)		{	low = 0;			high = 1096;	    } 	//c_a_sub
else if (i==35)		{	low = 0;			high = 1096;	    } 	//c_a_sub

else if (i==36)		{	low = 0;			high = 1;		}	//c_m_pop

else if (i==37)		{	low = 0;			high = 1;		}	//c_m_meta
else if (i==38)		{	low = 0;			high = 1;		}	//c_m_meta
else if (i==39)		{	low = 0;			high = 1;		}	//c_m_meta

else if (i==40)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==41)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==42)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==43)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==44)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==45)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==46)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==47)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==48)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==49)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==50)		{	low = 0;			high = 1;		}	//c_m_sub
else if (i==51)		{	low = 0;			high = 1;		}	//c_m_sub
//LARVAL DISPERSAL
else if (i==52)		{	low = 0;			high = 1096;	    } 	//l_a_pop

else if (i==53)		{	low = 0;			high = 1096;	    } 	//l_a_meta
else if (i==54)		{	low = 0;			high = 1096;  	} 	//l_a_meta
else if (i==55)		{	low = 0;			high = 1096;	    } 	//l_a_meta

else if (i==56)		{	low = 0;			high = 1096; 	    } 	//l_a_sub
else if (i==57)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==58)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==59)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==60)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==61)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==62)		{	low = 0;			high = 1096; 	    } 	//l_a_sub
else if (i==63)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==64)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==65)		{	low = 0;			high = 1096;  	} 	//l_a_sub
else if (i==66)		{	low = 0;			high = 1096;	    } 	//l_a_sub
else if (i==67)		{	low = 0;			high = 1096;	    }   //l_a_sub

else if (i==68)		{	low = 0;			high = 1;		}	//l_m_pop

else if (i==69)		{	low = 0;			high = 1;		}	//l_m_meta
else if (i==70)		{	low = 0;			high = 1;		}	//l_m_meta
else if (i==71)		{	low = 0;			high = 1;		}	//l_m_meta

else if (i==72)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==73)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==74)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==75)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==76)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==77)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==78)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==79)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==80)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==81)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==82)		{	low = 0;			high = 1;		}	//l_m_sub
else if (i==83)		{	low = 0;			high = 1;		}	//l_m_sub

//metapopulation four
else if (i==84)		{	low = 0;			high = 148;	} 	//initS
else if (i==85)		{	low = 0;			high = 0.9;		} 	//initV
else if (i==86)		{	low = 0;			high = 0.004;		} 	//initR

//metapopulation five
else if (i==87)		{	low = 0;			high = 148;	}	//initS
else if (i==88)		{	low = 0;			high = 0.9;		} 	//initV

//metapopulation six
else if (i==89)		{	low = 0;			high = 250;	} 	//initS
else if (i==90)		{	low = 0;			high = 0.9;		} 	//initV
else if (i==91)		{	low = 0;			high = 0.004;		} 	//initR

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PRIORS!!\n");	return 0;	}
}

double prior_bound_mcmc(int model, int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;
//metapopulation one
if(model==21){
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
    else if (i==14)		{	low = 0;			high = 50;		}	//Rsd_exp 
    else if (i==15)		{	low = 0;			high = 50;		}	//Fsd_exp 
    //pop c disp
    else if (i==16)		{	low = 0;			high = 1202604;	} 	//c_a_pop
    else if (i==17)		{	low = 0;			high = 1;		}	//c_m_pop
    //pop l disp
    else if (i==18)		{	low = 0;			high = 2000;	} 	//l_a_pop
    else if (i==19)		{	low = 0;			high = 1;		}	//l_m_pop

    if		(j==1)	return low;
    else if (j==2)	return high;
    else { printf("PROBLEM WITH BOUNDS ON PRIORS!!\n");	return 0; }
}
}
