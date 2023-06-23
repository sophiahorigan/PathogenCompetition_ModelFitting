int * fitting_routine_LS(int model){


    static int fitting_array[17];

    if(model==0){ //OBS PRIORS 
		fitting_array[0] = 0;

        fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		fitting_array[7] = 0;

        fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;
        
        fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}
	if(model==1){ //L POP, C NA, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==2){ //L POP, C NA, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==3){ //L POP, C NA, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}
	if(model==4){ //L META, C NA, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==5){ //L META, C NA, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==6){ //L META, C NA, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}	
	if(model==7){  //L SUB, C NA, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==8){ //L SUB, C NA, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==9){ //L SUB, C NA, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 0;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}	
	if(model==10){ //L NA, C POP, R POP
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==11){ //L NA, C POP, R META
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==12){ //L NA, C POP, R SUB
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}	
	if(model==13){//L NA, C META, R POP
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==14){//L NA, C META, R META
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==15){//L NA, C META, R SUB
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}	
	if(model==16){ //L NA, C SUB, R POP
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==17){//L NA, C SUB, R META
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}	
	if(model==18){//L NA, C SUB, R SUB
		fitting_array[0] = 0;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}
	if(model==19){ //L POP, C POP, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==20){//L POP, C POP, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}		
	if(model==21){//L POP, C POP, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}		
	if(model==22){//L POP, C META, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==23){//L POP, C META, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}		
	if(model==24){//L POP, C META, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}
	if(model==25){//L POP, C SUB, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==26){//L POP, C SUB, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}		
	if(model==27){//L POP, C SUB, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 1; 
		fitting_array[2] = 0;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 1; 
		fitting_array[5] = 0;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}
	if(model==28){//L META, C POP, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==29){//L META, C POP, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}								
	if(model==30){//L META, C POP, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}															
	if(model==31){//L META, C META, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==32){//L META, C META, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}								
	if(model==33){//L META, C META, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}									
	if(model==34){//L META, C SUB, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}	
	if(model==35){//L META, C SUB, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}								
	if(model==36){//L META, C SUB, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 1;
		fitting_array[3] = 0; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 1;
		fitting_array[6] = 0; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}	
	if(model==37){//L SUB, C POP, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}									
	if(model==38){//L SUB, C POP, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}																
	if(model==39){//L SUB, C POP, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 1;
		fitting_array[9] = 0;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 1;
		fitting_array[12] = 0;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}		
	if(model==40){//L SUB, C META, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}									
	if(model==41){//L SUB, C META, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}																
	if(model==42){//L SUB, C META, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 1;
		fitting_array[10] = 0;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 1;
		fitting_array[13] = 0;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}
	if(model==43){//L SUB, C SUB, R POP
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 1;
		fitting_array[15] = 0;
		fitting_array[16] = 0;
	}									
	if(model==44){//L SUB, C SUB, R META
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 1;
		fitting_array[16] = 0;
	}																
	if(model==45){//L SUB, C SUB, R SUB
		fitting_array[0] = 1;
		//a
		fitting_array[1] = 0; 
		fitting_array[2] = 0;
		fitting_array[3] = 1; 
		//m
		fitting_array[4] = 0; 
		fitting_array[5] = 0;
		fitting_array[6] = 1; 

		//CONIDIA DISPERSAL
		fitting_array[7] = 1;
		//a
		fitting_array[8] = 0;
		fitting_array[9] = 0;
		fitting_array[10] = 1;
		//m
		fitting_array[11] = 0;
		fitting_array[12] = 0;
		fitting_array[13] = 1;

		//RESTING SPORE DENSITY
		fitting_array[14] = 0;
		fitting_array[15] = 0;
		fitting_array[16] = 1;
	}																									

return(fitting_array);

}

int NumFitParams(int model){
	int NumberofParams;

	if(model==0){
		NumberofParams = 14;
	}
	if(model==1){
		NumberofParams = 10;
	}
	if(model==2){
		NumberofParams = 12;
	}
	if(model==3){
		NumberofParams = 18;
	}
	if(model==4){
		NumberofParams = 14;
	}
	if(model==5){
		NumberofParams = 16;
	}
	if(model==6){
		NumberofParams = 22;
	}
	if(model==7){
		NumberofParams = 32;
	}
	if(model==8){
		NumberofParams = 34;
	}
	if(model==9){
		NumberofParams = 40;
	}
	if(model==10){
		NumberofParams = 10;
	}
	if(model==11){
		NumberofParams = 12;
	}
	if(model==12){
		NumberofParams = 18;
	}
	if(model==13){
		NumberofParams = 14;
	}
	if(model==14){
		NumberofParams = 16;
	}
	if(model==15){
		NumberofParams = 22;
	}
	if(model==16){
		NumberofParams = 32;
	}
	if(model==17){
		NumberofParams = 34;
	}
	if(model==18){
		NumberofParams = 40;
	}
	if(model==19){
		NumberofParams = 12;
	}
	if(model==20){
		NumberofParams = 14;
	}
	if(model==21){
		NumberofParams = 20;
	}
	if(model==22){
		NumberofParams = 16;
	}
	if(model==23){
		NumberofParams = 18;
	}
	if(model==24){
		NumberofParams = 24;
	}
	if(model==25){
		NumberofParams = 34;
	}
	if(model==26){
		NumberofParams = 36;
	}
	if(model==27){
		NumberofParams = 42;
	}
	if(model==28){
		NumberofParams = 16;
	}
	if(model==29){
		NumberofParams = 18;
	}
	if(model==30){
		NumberofParams = 24;
	}
	if(model==31){
		NumberofParams = 20;
	}
	if(model==32){
		NumberofParams = 22;
	}
	if(model==33){
		NumberofParams = 28;
	}
	if(model==34){
		NumberofParams = 38;
	}
	if(model==35){
		NumberofParams = 40;
	}
	if(model==36){
		NumberofParams = 46;
	}
	if(model==37){
		NumberofParams = 34;
	}
	if(model==38){
		NumberofParams = 36;
	}
	if(model==39){
		NumberofParams = 42;
	}
	if(model==40){
		NumberofParams = 38;
	}
	if(model==41){
		NumberofParams = 40;
	}
	if(model==42){
		NumberofParams = 46;
	}
	if(model==43){
		NumberofParams = 56;
	}
	if(model==44){
		NumberofParams = 58;
	}
	if(model==45){
		NumberofParams = 64;
	}

	return(NumberofParams);
}
/*
void mcmc_assign_new(int model){

	if(model==0){ //OBS PRIORS //14
		//CORE SET
		Params.muV			= PCAparams[0]; //virus decay
		Params.CV			= PCAparams[1];//hetereogeneity to virus infection 
		Params.nuV    		= PCAparams[2]; //virus transmission
		Params.specific_nuF	= PCAparams[3]; //fungus transmissison
		Params.R_stoch 		= PCAparams[4];
		Params.F_stoch		= PCAparams[5];
		//meta 4
		Params.FITINIT[4][0] = PCAparams[6]; //initS
		Params.FITINIT[4][4] = PCAparams[7]; //initV
		Params.FITINIT[4][8] = PCAparams[8]; //initR
		//meta5
		Params.FITINIT[5][0] = PCAparams[9]; //initS
		Params.FITINIT[5][4] = PCAparams[10]; //initV
		//meta6
		Params.FITINIT[6][0] = PCAparams[11];//initS
		Params.FITINIT[6][4] = PCAparams[12]; //initV
		Params.FITINIT[6][8] = PCAparams[13]; //initR

	}
}

void mcmc_assign_old(int model){

	if(model==0){ //OBS PRIORS //14
		//CORE SET
		Params.muV			= Old_Params[0]; //virus decay
		Params.CV			= Old_Params[1];//hetereogeneity to virus infection 
		Params.nuV    		= Old_Params[2]; //virus transmission
		Params.specific_nuF	= Old_Params[3]; //fungus transmissison
		Params.R_stoch 		= Old_Params[4];
		Params.F_stoch		= Old_Params[5];
		//meta 4
		Params.FITINIT[4][0] = Old_Params[6]; //initS
		Params.FITINIT[4][4] = Old_Params[7]; //initV
		Params.FITINIT[4][8] = Old_Params[8]; //initR
		//meta5
		Params.FITINIT[5][0] = Old_Params[9]; //initS
		Params.FITINIT[5][4] = Old_Params[10]; //initV
		//meta6
		Params.FITINIT[6][0] = Old_Params[11];//initS
		Params.FITINIT[6][4] = Old_Params[12]; //initV
		Params.FITINIT[6][8] = Old_Params[13]; //initR

	}			

}*/

