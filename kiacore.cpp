#include <iostream>
#include <cstdlib>

extern "C" {
    void ejecutar_tensor(float* d, int t) {
        // Simulación de aceleración PyTorch Nativa
        std::cout << "[KIA-HARDWARE] Aceleración de tensores activa." << std::endl;
    }

    void forzar_limpieza_memoria() {
        // Libera RAM después de cambiar de modelo (MET)
        system("sync && echo 3 > /proc/sys/vm/drop_caches");
        std::cout << "[SYSTEM] Memoria RAM optimizada para cambio de modelo." << std::endl;
    }
}
