#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>

/* Navega nos diretórios. */

static void navegaRecursivo ( const char * nome_dir )
{
   DIR * diretorio;

   /* Abre o diretório "nome_dir". */

   diretorio = opendir (nome_dir);

   /* Verifica se o arquivo foi aberto corretamente. */
   if (! diretorio) 
	{
        fprintf (stderr, "Nao foi possivel abrir o diretorio '%s': %s\n", nome_dir, strerror (errno));
        exit (EXIT_FAILURE);
   }
   while (1) /* Loop termina com break */
   {
       struct dirent * dir_struct;
       const char * dir_struct_nome;
       dir_struct = readdir (diretorio);
       if (! dir_struct)
		 {
           /* Não há mais diretórios */
           break;
       }
       dir_struct_nome = dir_struct->d_name;
       /* Imprime diretório. */
       printf ("%s/%s\n", nome_dir, dir_struct_nome);

       /* Aceita apenas subdiretórios */

       if (dir_struct->d_type & DT_DIR)
		 {

           /* Garante a navegação apenas no interior do diretório. */

          if ( strcmp (dir_struct_nome, "..") != 0 && strcmp (dir_struct_nome, ".") != 0 )
          {
             int tamanho_caminho;
             char caminho[PATH_MAX];

             tamanho_caminho = snprintf ( caminho , PATH_MAX , "%s/%s", nome_dir, dir_struct_nome);
             printf ("%s\n", caminho);

             if (tamanho_caminho >= PATH_MAX)
             {

                fprintf (stderr, "Caminho muito longo.\n");
                exit (EXIT_FAILURE);
             }

             /* Refazer processo na pasta "caminho" */
             navegaRecursivo(caminho);
         }
      }
   }
		 /* Fechar diretórios */
   if (closedir (diretorio))
   {
       fprintf (stderr, "Nao foi possivel fechar '%s': %s\n", nome_dir, strerror (errno));
       exit (EXIT_FAILURE);
   }
}
