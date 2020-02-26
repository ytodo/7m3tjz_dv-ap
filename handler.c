#include "dv_ap.h"

void	handler (int sig)
{

	if (sig == SIGTERM) sig_term = TRUE;
	else if (sig == SIGINT)  sig_term = TRUE;
	else if (sig == SIGUSR2)
	{
		time(&cur_time);
		if (debug)
		{
			fprintf (log_file, "%24.24s Leave Debug Mode\n",ctime(&cur_time));
			debug = FALSE;
		}
		else
		{
			fprintf (log_file, "%24.24s Enter Debug Mode\n",ctime(&cur_time));
			debug = TRUE;
		}
		fflush (log_file);
	}
}

int	handler_init(void)
{
	time (&cur_time);
	if (signal(SIGUSR1, handler) == SIG_ERR)
	{
		fprintf (log_file, "%24.24s signal (SIGUSR1) error\n", ctime(&cur_time));
		fflush (log_file);
		return FALSE;
	}	
	if (signal(SIGUSR2, handler) == SIG_ERR)
	{
		fprintf (log_file, "%24.24s signal (SIGUSR2) error\n", ctime(&cur_time));
		fflush (log_file);
                return FALSE;
        }
        if (signal(SIGTERM, handler) == SIG_ERR)
        {
                fprintf (log_file, "%24.24s signal (SIGTERM) error\n", ctime(&cur_time));
                fflush (log_file);
                return FALSE;
        }
        if (signal(SIGINT, handler) == SIG_ERR)
        {
                fprintf (log_file, "%24.24s signal (SIGINT) error\n", ctime(&cur_time));
                fflush (log_file);
                return FALSE;
        }


	return TRUE;
}
