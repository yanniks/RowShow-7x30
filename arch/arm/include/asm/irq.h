#ifndef __ASM_ARM_IRQ_H
#define __ASM_ARM_IRQ_H

#include <mach/irqs.h>

#ifndef irq_canonicalize
#define irq_canonicalize(i)	(i)
#endif

#define NR_IRQS_LEGACY	16

/*
 * Use this value to indicate lack of interrupt
 * capability
 */
#ifndef NO_IRQ
#define NO_IRQ	((unsigned int)(-1))
#endif

#ifndef __ASSEMBLY__
struct irqaction;
struct pt_regs;
extern void migrate_irqs(void);

extern void asm_do_IRQ(unsigned int, struct pt_regs *);
<<<<<<< HEAD
void handle_IRQ(unsigned int, struct pt_regs *);
=======
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
void init_IRQ(void);

#endif

#endif

