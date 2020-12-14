/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include "my.h"
#include <signal.h>
#include "navy.h"
#include "print.h"

extern glo *glb;

void hand_sig(int signbr, siginfo_t *siginfo, void *text)
{
    (void)text;
    if (signbr == SIGUSR1 && glb->type == 0) {
        glb->pid2 = siginfo->si_pid;
        glb->sleep_or_not = 1;
    }
    if (signbr == SIGUSR1 && glb->type == 1 && glb->end == 0)
        glb->column++;
    if (signbr == SIGUSR1 && glb->type == 1 && glb->end > 0)
        glb->sleep_or_not = 1;
    if (signbr == SIGUSR2 && glb->type == 1)
        glb->line++, glb->end = 1;
    if (signbr == SIGUSR1 && glb->type == 2)
        glb->hit = 1, glb->sleep_or_not = 1;
    if (signbr == SIGUSR2 && glb->type == 2)
        glb->hit = 2, glb->sleep_or_not = 1;
}

void set_sig(void)
{
    struct sigaction sa;
    sigset_t mask;

    sigemptyset(&mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_mask = mask;
    sa.sa_sigaction = hand_sig;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void stup_glo(void)
{
    glb = malloc(sizeof(glo));
    glb->type = 0;
    glb->column = 0;
    glb->line = 0;
    glb->sleep_or_not = 0;
    glb->end = 0;
    set_sig();
    glb->pid1 = getpid();
    glb->hit = 0;
    glb->win = 0;
    glb->loss = 0;
}