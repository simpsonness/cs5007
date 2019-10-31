#include <stdio.h>
#include <time.h>    

int count = 0;
double time_spent = 0.0;
clock_t begin;
clock_t end;
	
void
__attribute__ ((constructor))
trace_begin (void)
{
	begin = clock();
}
 
void
__attribute__ ((destructor))
trace_end (void)
{
	end = clock();
  	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time elpased is %f seconds\n", time_spent);
	printf("Total Functions is %d times\n", count);

}

__attribute__((no_instrument_function))
void __cyg_profile_func_enter(void *this_fn, void *call_site){

	printf("Function entered\n");

}

__attribute__((no_instrument_function))
void __cyg_profile_func_exit(void *this_fn, void *call_site){

	printf("Function exited\n");
	count += 1;

}

