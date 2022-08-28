/*
 * KLD Sample Module
 * Extracted from FreeBSD Handbook. Chapter 9
 * https://docs.freebsd.org/en/books/arch-handbook/driverbasics/
 */

#include <sys/types.h>
#include <sys/systm.h>  /* uprintf */
#include <sys/errno.h>
#include <sys/param.h>  /* defines used in kernel.h */
#include <sys/module.h>
#include <sys/kernel.h> /* types used in module initialization */

/*
 * Load handler that deals with the loading and unloading of a KLD.
 */

static int
morse_loader(struct module *m, int what, void *arg)
{
  int err = 0;

  switch (what) {
  case MOD_LOAD:                /* kldload */
    uprintf("Morse KLD loaded.\n");
    break;
  case MOD_UNLOAD:
    uprintf("Morse KLD unloaded.\n");
    break;
  default:
    err = EOPNOTSUPP;
    break;
  }
  return(err);
}

/* Declare this module to the rest of the kernel */

static moduledata_t morse_mod = {
  "morse",
  morse_loader,
  NULL
};

DECLARE_MODULE(morse, morse_mod, SI_SUB_KLD, SI_ORDER_ANY);
