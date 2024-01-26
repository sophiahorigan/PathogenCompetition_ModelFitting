int* dispersal_fit(int model){

	int static fitting_array[17];

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

int* which_fit(int model){

    int static fit_array[92];

	if(model==0){ //OBS
		fit_array[14] = fit_array[15] = fit_array[16] = fit_array[17] = fit_array[18] = fit_array[19] = fit_array[84] = fit_array[85] = fit_array[86] = fit_array[87] = fit_array[88] = fit_array[89] = fit_array[90] = fit_array[91] = 1;
	}
	if(model==1){ //L POP, C NA, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==2){ //L POP, C NA, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==3){ //L POP, C NA, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==4){ //L META, C NA, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==5){ //L META, C NA, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==6){ //L META, C NA, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==7){ //L SUB, C NA, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==8){ //L SUB, C NA, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==9){ //L SUB, C NA, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==10){ //L NA, C POP, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = 1;
	}
	if(model==11){ //L NA, C POP, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = 1;
	}
	if(model==12){ //L NA, C POP, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = 1;
	}
	if(model==13){ //L NA, C META, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = 1;
	}
	if(model==14){ //L NA, C META, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = 1;
	}
	if(model==15){ //L NA, C META, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = 1;
	}
	if(model==16){ //L NA, C SUB, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = 1;
	}
	if(model==17){ //L NA, C SUB, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = 1;
	}
	if(model==18){ //L NA, C SUB, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = 1;
	}
	if(model==19){ //L POP, C POP, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==20){ //L POP, C POP, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==21){ //L POP, C POP, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==22){ //L POP, C META, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==23){ //L POP, C META, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==24){ //L POP, C META, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==25){ //L POP, C SUB, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==26){ //L POP, C SUB, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==27){ //L POP, C SUB, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[52] = fit_array[68] = 1;
	}
	if(model==28){ //L META, C POP, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==29){ //L META, C POP, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==30){ //L META, C POP, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	} 
	if(model==31){ //L META, C META, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==32){ //L META, C META, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==33){ //L META, C META, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==34){ //L META, C SUB, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==35){ //L META, C SUB, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==36){ //L META, C SUB, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[53] = fit_array[54] = fit_array[55] = fit_array[69] = fit_array[70] = fit_array[71] = 1;
	}
	if(model==37){ //L SUB, C POP, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==38){ //L SUB, C POP, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] =fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==39){ //L SUB, C POP, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[20] = fit_array[36] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==40){ //L SUB, C META, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==41){ //L SUB, C META, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==42){ //L SUB, C META, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[21] = fit_array[22] = fit_array[23] = fit_array[37] = fit_array[38] = fit_array[39] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==43){ //L SUB, C SUB, R POP
		fit_array[0] = fit_array[1] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==44){ //L SUB, C SUB, R META
		fit_array[0] = fit_array[2] = fit_array[3] = fit_array[4] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}
	if(model==45){ //L SUB, C SUB, R SUB
		fit_array[0] = fit_array[5] = fit_array[6] = fit_array[7] = fit_array[8] = fit_array[9] = fit_array[10] = fit_array[11] = fit_array[12] = fit_array[13] = fit_array[18] = fit_array[19] = fit_array[24] = fit_array[25] = fit_array[26] = fit_array[27] = fit_array[28] = fit_array[29] = fit_array[30] = fit_array[31] = fit_array[32] = fit_array[33] = fit_array[34] = fit_array[35] = fit_array[40] = fit_array[41] = fit_array[42] = fit_array[43] = fit_array[44] = fit_array[45] = fit_array[46] = fit_array[47] = fit_array[48] = fit_array[49] = fit_array[50] = fit_array[51] = fit_array[56] = fit_array[57] = fit_array[58] = fit_array[59] = fit_array[60] = fit_array[61] = fit_array[62] = fit_array[63] = fit_array[64] = fit_array[65] = fit_array[66] = fit_array[67] = fit_array[72] = fit_array[73] = fit_array[74] = fit_array[75] = fit_array[76] = fit_array[77] = fit_array[78] = fit_array[79] = fit_array[80] = fit_array[81] = fit_array[82] = fit_array[83] = 1;
	}

	return(fit_array);
}

int NumFitParams(int model){
	int NumberofParams;

	if(model==0){
		NumberofParams = 10;
	}
	if(model==1){
		NumberofParams = 6;
	}
	if(model==2){
		NumberofParams = 8;
	}
	if(model==3){
		NumberofParams = 14;
	}
	if(model==4){
		NumberofParams = 10;
	}
	if(model==5){
		NumberofParams = 12;
	}
	if(model==6){
		NumberofParams = 18;
	}
	if(model==7){
		NumberofParams = 28;
	}
	if(model==8){
		NumberofParams = 30;
	}
	if(model==9){
		NumberofParams = 36;
	}
	if(model==10){
		NumberofParams = 6;
	}
	if(model==11){
		NumberofParams = 8;
	}
	if(model==12){
		NumberofParams = 14;
	}
	if(model==13){
		NumberofParams = 10;
	}
	if(model==14){
		NumberofParams = 12;
	}
	if(model==15){
		NumberofParams = 18;
	}
	if(model==16){
		NumberofParams = 28;
	}
	if(model==17){
		NumberofParams = 30;
	}
	if(model==18){
		NumberofParams = 36;
	}
	if(model==19){
		NumberofParams = 8;
	}
	if(model==20){
		NumberofParams = 10;
	}
	if(model==21){
		NumberofParams = 16;
	}
	if(model==22){
		NumberofParams = 12;
	}
	if(model==23){
		NumberofParams = 14;
	}
	if(model==24){
		NumberofParams = 20;
	}
	if(model==25){
		NumberofParams = 30;
	}
	if(model==26){
		NumberofParams = 32;
	}
	if(model==27){
		NumberofParams = 38;
	}
	if(model==28){
		NumberofParams = 12;
	}
	if(model==29){
		NumberofParams = 14;
	}
	if(model==30){
		NumberofParams = 20;
	}
	if(model==31){
		NumberofParams = 16;
	}
	if(model==32){
		NumberofParams = 18;
	}
	if(model==33){
		NumberofParams = 24;
	}
	if(model==34){
		NumberofParams = 34;
	}
	if(model==35){
		NumberofParams = 36;
	}
	if(model==36){
		NumberofParams = 42;
	}
	if(model==37){
		NumberofParams = 30;
	}
	if(model==38){
		NumberofParams = 32;
	}
	if(model==39){
		NumberofParams = 38;
	}
	if(model==40){
		NumberofParams = 34;
	}
	if(model==41){
		NumberofParams = 36;
	}
	if(model==42){
		NumberofParams = 42;
	}
	if(model==43){
		NumberofParams = 52;
	}
	if(model==44){
		NumberofParams = 54;
	}
	if(model==45){
		NumberofParams = 60;
	}

	return(NumberofParams);
}
