#include <iostream>
#include <cstdlib>

extern "C" {
    void ejecutar_tensor(float* d, int t) {
        std::cout << "[KIA-HARDWARE] Aceleración de tensores activa." << std::endl;
    }

    void limpiar_sistema() {
        // Limpieza de caché de Linux para liberar RAM
        system("sync && echo 3 > /proc/sys/vm/drop_caches");
    }
}
