#include <parser.h>

int		main(void)
{
	t_mywin	w;

	w = test_creation();
	sauvegarde("fichier_sauvegarder.test", &(w.polygon_lst));
}
