double ls_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

if (i==0)			{	low = 0;			high = 5;	    }	//initS //1-148

//INITR
//pop
else if (i==1)		{	low = -11.5;		high = -5.5;	}	//initR POP //0-0.004
//meta
else if (i==2)		{	low = -11.5;		high = -5.5;	}	//initR META 1 //0-0.004
else if (i==3)		{	low = -11.5;		high = -5.5;	}	//initR META 2 //0-0.004
else if (i==4)		{	low = -11.5;		high = -5.5;	}	//initR META 3//0-0.004
//sub
//1
else if (i==5)		{	low = -11.5;		high = -5.5;	}	//initR meta 1 sub1 //0-0.004
//2
else if (i==6)		{	low = -11.5;		high = -5.5;	}	//initR meta 2 sub1 //0-0.004
else if (i==7)		{	low = -11.5;		high = -5.5;	}	//initR meta 2 sub2 //0-0.004
else if (i==8)		{	low = -11.5;		high = -5.5;	}	//initR meta 2 sub3 //0-0.004
else if (i==9)		{	low = -11.5;		high = -5.5;	}	//initR meta 2 sub4 //0-0.004
//3
else if (i==10)		{	low = -11.5;		high = -5.5;	}	//initR meta 3 sub1 //0-0.004
else if (i==11)		{	low = -11.5;		high = -5.5;	}	//initR meta 3 sub2 //0-0.004
else if (i==12)		{	low = -11.5;		high = -5.5;	}	//initR meta 3 sub3 //0-0.004
else if (i==13)		{	low = -11.5;		high = -5.5;	}	//initR meta 3 sub4 //0-0.004
//VIRUS PARAMS
else if (i==14)		{	low = -11.5;		high = -4.6;	}	//Fuller 2012 //virus decay //0.39 //muV
else if (i==15)		{	low = -1.2;			high = 1;		}	//virus heterogeneity
else if (i==16)		{	low = -4.6;			high = -0.0001;	}  //virus transmission //0.01 - 1
//FUNGUS PARAMS
else if (i==17)		{	low = -11.5;		high = -5.5;	} 	//fungus transmission //0.00001 - 0.004
//STOCHASTICITY
else if (i==18)		{	low = -7;			high = 1.3;		}	//Rsd	//0-3
else if (i==19)		{	low = -7;			high = 1.1;		}	//Fsd   //0-3
//CONIDIA DISPERSAL
else if (i==20)		{	low = -8.5;			high = -0.0001;	}  // a_c_pop //0 - 1

else if (i==21)		{	low = -8.5;			high = -0.0001;	}  // a_c_meta1
else if (i==22)		{	low = -8.5;			high = -0.0001;	}  // a_c_meta2
else if (i==23)		{	low = -8.5;			high = -0.0001;	}  // a_c_meta3

else if (i==24)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub //meta1
else if (i==25)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==26)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==27)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub

else if (i==28)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub //meta2
else if (i==29)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==30)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==31)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub

else if (i==32)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub //meta3
else if (i==33)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==34)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub
else if (i==35)		{	low = -8.5;			high = -0.0001;	}  // a_c_sub

else if (i==36)		{	low = -8.5;			high = -0.0001;	} //m_c_pop //0 - 1

else if (i==37)		{	low = -8.5;			high = -0.0001;	} //m_c_meta1
else if (i==38)		{	low = -8.5;			high = -0.0001;	} //m_c_meta2
else if (i==39)		{	low = -8.5;			high = -0.0001;	} //m_c_meta3

else if (i==40)		{	low = -8.5;			high = -0.0001;	} //m_c_sub //meta1
else if (i==41)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==42)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==43)		{	low = -8.5;			high = -0.0001;	} //m_c_sub

else if (i==44)		{	low = -8.5;			high = -0.0001;	} //m_c_sub //meta2
else if (i==45)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==46)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==47)		{	low = -8.5;			high = -0.0001;	} //m_c_sub

else if (i==48)		{	low = -8.5;			high = -0.0001;	} //m_c_sub //meta3
else if (i==49)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==50)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
else if (i==51)		{	low = -8.5;			high = -0.0001;	} //m_c_sub
//LARVAL DISPERSAL
else if (i==52)		{	low = -8.5;			high = -0.0001;	}  // a_l_pop

else if (i==53)		{	low = -8.5;			high = -0.0001;	}  // a_l_meta1
else if (i==54)		{	low = -8.5;			high = -0.0001;	}  // a_l_meta2
else if (i==55)		{	low = -8.5;			high = -0.0001;	}  // a_l_meta3

else if (i==56)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub //meta1
else if (i==57)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==58)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==59)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub

else if (i==60)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub //meta2
else if (i==61)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==62)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==63)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub

else if (i==64)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub //meta3
else if (i==65)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==66)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub
else if (i==67)		{	low = -8.5;			high = -0.0001;	}  // a_l_sub

else if (i==68)		{	low = -8.5;			high = -0.0001; } //m_l_pop

else if (i==69)		{	low = -8.5;			high = -0.0001; } //m_l_meta1
else if (i==70)		{	low = -8.5;			high = -0.0001; } //m_l_meta2
else if (i==71)		{	low = -8.5;			high = -0.0001; } //m_l_meta3

else if (i==72)		{	low = -8.5;			high = -0.0001; } //m_l_sub //meta1
else if (i==73)		{	low = -8.5;			high = -0.0001; } //m_l_sub
else if (i==74)		{	low = -8.5;			high = -0.0001;	} //m_l_sub
else if (i==75)		{	low = -8.5;			high = -0.0001;	} //m_l_sub

else if (i==76)		{	low = -8.5;			high = -0.0001;	} //m_l_sub //meta2
else if (i==77)		{	low = -8.5;			high = -0.0001;	} //m_l_sub
else if (i==78)		{	low = -8.5;			high = -0.0001;	} //m_l_sub
else if (i==79)		{	low = -8.5;			high = -0.0001;	} //m_l_sub

else if (i==80)		{	low = -8.5;			high = -0.0001; } //m_l_sub //meta3
else if (i==81)		{	low = -8.5;			high = -0.0001; } //m_l_sub
else if (i==82)		{	low = -8.5;			high = -0.0001;	} //m_l_sub
else if (i==83)		{	low = -8.5;			high = -0.0001;	} //m_l_sub

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
// ------------------------------------------------------------------------------------ //
double prior_bound(int i,int j)				// bounds on parameters for parhood line search
{
double low;
double high;

//metapopulation one
if (i==0)			{	low = 0;			high = 5000;    }	//initS 
//INIT R
//pop
else if (i==1)		{	low = 0;			high = 1;		}	//initR 
//meta
else if (i==2)		{	low = 0;			high = 1;		}	//initR 
else if (i==3)		{	low = 0;			high = 1;		}	//initR 
else if (i==4)		{	low = 0;			high = 1;		}	//initR 
//sub
else if (i==5)		{	low = 0;			high = 1;		}	//initR 
else if (i==6)		{	low = 0;			high = 1;		}	//initR 
else if (i==7)		{	low = 0;			high = 1;		}	//initR 
else if (i==8)		{	low = 0;			high = 1;		}	//initR 
else if (i==9)		{	low = 0;			high = 1;		}	//initR 
else if (i==10)		{	low = 0;			high = 1;		}	//initR 
else if (i==11)		{	low = 0;			high = 1;		}	//initR 
else if (i==12)		{	low = 0;			high = 1;		}	//initR 
else if (i==13)		{	low = 0;			high = 1;		}	//initR 

//VIRUS PARAMS
else if (i==14)		{	low = 0;			high = 5;		} 	//virus decay rate

else if (i==15) 	{	low = 0;			high = 10;		}	//heterogeneity
else if (i==16)	    {	low = 0; 			high = 	10;	    }	//virus transmission
//FUNGUS PARAM
else if (i==17) 	{	low = 0;			high = 1;		}	//fungus transmission
//STOCHASTICITY
else if (i==18)		{	low = 0;			high = 10;		}	//Rsd_exp
else if (i==19)		{	low = 0;			high = 10;		}	//Fsd_exp
//CONIDIA DISPERSAL
else if (i==20)		{	low = 0;			high = 100;	    } 	//c_a_pop

else if (i==21)		{	low = 0;			high = 100;	    } 	//c_a_meta
else if (i==22)		{	low = 0;			high = 100;	    } 	//c_a_meta
else if (i==23)		{	low = 0;			high = 100;	    } 	//c_a_meta

else if (i==24)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==25)		{	low = 0;			high = 100;	    }  	//c_a_sub
else if (i==26)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==27)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==28)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==29)		{	low = 0;			high = 100; 	} 	//c_a_sub
else if (i==30)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==31)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==32)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==33)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==34)		{	low = 0;			high = 100;	    } 	//c_a_sub
else if (i==35)		{	low = 0;			high = 100;	    } 	//c_a_sub

else if (i==36)		{	low = 0;			high = 100;		}	//c_m_pop

else if (i==37)		{	low = 0;			high = 100;		}	//c_m_meta
else if (i==38)		{	low = 0;			high = 100;		}	//c_m_meta
else if (i==39)		{	low = 0;			high = 100;		}	//c_m_meta

else if (i==40)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==41)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==42)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==43)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==44)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==45)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==46)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==47)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==48)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==49)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==50)		{	low = 0;			high = 100;		}	//c_m_sub
else if (i==51)		{	low = 0;			high = 100;		}	//c_m_sub
//LARVAL DISPERSAL
else if (i==52)		{	low = 0;			high = 100;	    } 	//l_a_pop

else if (i==53)		{	low = 0;			high = 100;	    } 	//l_a_meta
else if (i==54)		{	low = 0;			high = 100; 	} 	//l_a_meta
else if (i==55)		{	low = 0;			high = 100;	    } 	//l_a_meta

else if (i==56)		{	low = 0;			high = 100; 	} 	//l_a_sub
else if (i==57)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==58)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==59)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==60)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==61)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==62)		{	low = 0;			high = 100; 	} 	//l_a_sub
else if (i==63)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==64)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==65)		{	low = 0;			high = 100; 	} 	//l_a_sub
else if (i==66)		{	low = 0;			high = 100;	    } 	//l_a_sub
else if (i==67)		{	low = 0;			high = 100;	    }   //l_a_sub

else if (i==68)		{	low = 0;			high = 100;		}	//l_m_pop

else if (i==69)		{	low = 0;			high = 100;		}	//l_m_meta
else if (i==70)		{	low = 0;			high = 100;		}	//l_m_meta
else if (i==71)		{	low = 0;			high = 100;		}	//l_m_meta

else if (i==72)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==73)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==74)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==75)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==76)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==77)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==78)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==79)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==80)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==81)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==82)		{	low = 0;			high = 100;		}	//l_m_sub
else if (i==83)		{	low = 0;			high = 100;		}	//l_m_sub
//metapopulation four
else if (i==84)		{	low = 0;			high = 5000;	} 	//initS
else if (i==85)		{	low = 0;			high = 1;		} 	//initV
else if (i==86)		{	low = 0;			high = 1;		} 	//initR

//metapopulation five
else if (i==87)		{	low = 0;			high = 5000;	}	//initS
else if (i==88)		{	low = 0;			high = 1;		} 	//initV

//metapopulation six
else if (i==89)		{	low = 0;			high = 5000;	} 	//initS
else if (i==90)		{	low = 0;			high = 1;		} 	//initV
else if (i==91)		{	low = 0;			high = 1;		} 	//initR

if		(j==1)	return low;
else if (j==2)	return high;
else { printf("PROBLEM WITH BOUNDS ON PRIORS!!\n");	return 0;	}
}
