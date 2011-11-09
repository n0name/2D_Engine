#ifndef TYPES_H
#define TYPES_H

typedef struct _point_t{
    Uint16 x, y;
}point_t;

struct ThreadData_t {
        SDL_mutex *graphMutex;
        SDL_Thread *thread;
        int flag;
};


#define ERROR(E) printf("\n%s : %d : ERROR: %s",__FILE__,__LINE__,#E);

#endif // TYPES_H
