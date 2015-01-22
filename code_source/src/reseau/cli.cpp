#include "reseau.hpp"
#include <unistd.h>
#include <pthread.h>

void* afficher_reception(void* arg){

	Client * cli = (Client*)arg;

	std::string affichage_standard("que je suis accepté");
	while(1){
		if((affichage_standard = cli->recevoir()) != "")
			std::cout << "\n Un autre joueur dit : " << affichage_standard << std::endl;
	}

	return nullptr;
		
}

int main(){

	std::string a;

	std::cin >> a;

	Client cli(a);

	pthread_t thread;

	pthread_create(&thread, nullptr, afficher_reception, &cli);

	while(1){
		std::cin >> a;
		cli.envoyer(a);
	}

	return 0;
}

