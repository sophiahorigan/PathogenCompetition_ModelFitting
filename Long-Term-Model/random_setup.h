gsl_rng *random_setup(void)
{
const gsl_rng_type *TT;
long seedy;
srand((unsigned) time(NULL));
//seedy = -rand();
seedy = time(NULL)*(int)getpid();    
gsl_rng_env_setup ();
gsl_rng_default_seed = seedy;
TT = gsl_rng_default;

return gsl_rng_alloc(TT);
}
