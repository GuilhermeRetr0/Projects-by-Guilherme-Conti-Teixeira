#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <json-c/json.h>

#define API_KEY "SUA_API_KEY_AQUI"

// Função para fazer a requisição à API e retornar a resposta em JSON
char* make_request(char* city) {
    CURL *curl;
    CURLcode res;
    char url[100];
    sprintf(url, "http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s", city, API_KEY);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        char *response = malloc(1);
        response[0] = '\0';
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return response;
    }
    return "";
}

// Função para imprimir os dados de clima da cidade
void print_weather(char* response) {
    struct json_object *root, *weather, *main, *temp, *humidity, *description;
    root = json_tokener_parse(response);
    json_object_object_get_ex(root, "weather", &weather);
    json_object_object_get_ex(weather, "description", &description);
    json_object_object_get_ex(root, "main", &main);
    json_object_object_get_ex(main, "temp", &temp);
    json_object_object_get_ex(main, "humidity", &humidity);
    printf("Descrição: %s\n", json_object_get_string(description));
    printf("Temperatura: %.2f°C\n", json_object_get_double(temp) - 273.15);
    printf("Umidade: %d%%\n", json_object_get_int(humidity));
}

// Função principal do programa
int main() {
    char city[50];
    printf("Digite o nome da cidade: ");
    scanf("%s", city);
    char* response = make_request(city);
    print_weather(response);
    free(response);
    return 0;
}
