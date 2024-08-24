//inclui bibliotecas usadas no projeto
#include <iostream>
#include <limits>
#include <chrono>
#include <format>
#include <string>
#include <cmath>

void lida_Com_Dados_Invalidos();
bool extra_dados();
bool checa_Opcao_Invalida_Digitada(char tipo_data);

using namespace std::chrono;

auto hoje = system_clock::now();
auto hoje_data = floor<days>(hoje);

unsigned int mes, dia;
int ano;


void lida_Com_Dados_Invalidos()
{

    //limpa buffer de entrada
    std::cin.clear();

    //ignora a próxima linha
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //pede para o usuário que digitou uma opção inválida, digite uma opção válida
    std::cout << "Digite uma opcao valida" << std::endl;

}

bool extrai_Dados()
{

    //usuário inputa os dados

    std::cout << "Digite o ano que voce nasceu: " << std::endl;
    std::cin >> ano;
    if (checa_Opcao_Invalida_Digitada('a')) 
    {
        lida_Com_Dados_Invalidos();
        return true;
    }
    std::cout << "Digite o mes que voce nasceu:" << std::endl;
    std::cin >> mes;
    if (checa_Opcao_Invalida_Digitada('m')) 
    {
        lida_Com_Dados_Invalidos();
        return true;
    }
    std::cout << "Digite o dia que voce nasceu: " << std::endl;
    std::cin >> dia;
    if (checa_Opcao_Invalida_Digitada('d')) 
    {
        lida_Com_Dados_Invalidos();
        return true;
    }

    //retorna que os dados são válidos
    return false;

}

//checa opções inválidas digitadas
bool checa_Opcao_Invalida_Digitada(char tipo_data)
{

        //lida com falhas no input
        if(std::cin.fail())
        {

            return true;
            
        }

        //verifica se o mes existe
        if((mes > 12 || mes < 1) && tipo_data == 'm')
        {
            return true;
        }

        //verifica se o dia existe
        if((dia > 31 || dia < 1) && tipo_data == 'd')
        {
            return true;
        }

        //retorna que os dados são válidos
        return false;


}

//função inicial do programa
int main()
{

    while(extrai_Dados()){}

    auto data_nascimento = sys_days{year{ano}/month{mes}/day{dia}};

    // cálcula a diferença entre as datas
    auto diferenca_datas = hoje - data_nascimento;

    // Printa a idade da pessoa
    std::cout << "Voce tem " << std::chrono::duration_cast<std::chrono::years>(diferenca_datas).count() << " anos, ";
    std::cout << std::chrono::duration_cast<std::chrono::months>(diferenca_datas % std::chrono::years(1)).count() << " meses e ";
    std::cout << std::chrono::duration_cast<std::chrono::days>(diferenca_datas % std::chrono::months(1)).count() << " dias de vida." << std::endl;

}