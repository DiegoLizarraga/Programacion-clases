#include "imgui/imgui.h"
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Clase base para contenido multimedia
class ContenidoMultimedia {
protected:
    string titulo;
    float calificacion;
    int duracion; // en minutos
    string genero;
    string imagen;
    vector<string> videos;

public:
    ContenidoMultimedia(string t, float c, int d, string g, string img) 
        : titulo(t), calificacion(c), duracion(d), genero(g), imagen(img) {}
    
    virtual void mostrarInfo() = 0;
    virtual void mostrarVideos() = 0;
    virtual void mostrarImagen() = 0;
    
    string getTitulo() { return titulo; }
    float getCalificacion() { return calificacion; }
    int getDuracion() { return duracion; }
    string getGenero() { return genero; }
};

// Clase Película
class Pelicula : public ContenidoMultimedia {
private:
    string director;
    int año;

public:
    Pelicula(string t, float c, int d, string g, string dir, int a, string img) 
        : ContenidoMultimedia(t, c, d, g, img), director(dir), año(a) {
        videos.push_back("Trailer Oficial - " + titulo);
        videos.push_back("Making Of - " + titulo);
        videos.push_back("Escenas Eliminadas - " + titulo);
    }
    
    void mostrarInfo() override {
        ImGui::Text("======== PELICULA ========");
        ImGui::Text("Titulo: %s", titulo.c_str());
        ImGui::Text("Calificación: %.1f/10", calificacion);
        ImGui::Text("Duración: %d minutos", duracion);
        ImGui::Text("Género: %s", genero.c_str());
        ImGui::Text("Director: %s", director.c_str());
        ImGui::Text("Año: %d", año);
        ImGui::Text("=========================");
    }
    
    void mostrarVideos() override {
        ImGui::Text("--- VIDEOS DISPONIBLES ---");
        for(size_t i = 0; i < videos.size(); i++) {
            ImGui::Text("%d. %s", (int)(i+1), videos[i].c_str());
        }
        ImGui::Text("-------------------------");
    }
    
    void mostrarImagen() override {
        ImGui::Text("--- IMAGEN/POSTER ---");
        ImGui::Text("Imagen: %s", imagen.c_str());
        ImGui::Text("--------------------");
    }
};

// Clase Serie
class Serie : public ContenidoMultimedia {
private:
    int temporadas;
    int episodios;
    string creador;

public:
    Serie(string t, float c, int d, string g, int temp, int ep, string cr, string img) 
        : ContenidoMultimedia(t, c, d, g, img), temporadas(temp), episodios(ep), creador(cr) {
        videos.push_back("Trailer Temporada 1 - " + titulo);
        videos.push_back("Trailer Temporada " + to_string(temporadas) + " - " + titulo);
        videos.push_back("Bloopers - " + titulo);
        videos.push_back("Entrevista con el reparto - " + titulo);
    }
    
    void mostrarInfo() override {
        ImGui::Text("========= SERIE ==========");
        ImGui::Text("Título: %s", titulo.c_str());
        ImGui::Text("Calificación: %.1f/10", calificacion);
        ImGui::Text("Duración por episodio: %d minutos", duracion);
        ImGui::Text("Género: %s", genero.c_str());
        ImGui::Text("Temporadas: %d", temporadas);
        ImGui::Text("Episodios totales: %d", episodios);
        ImGui::Text("Creador: %s", creador.c_str());
        ImGui::Text("=========================");
    }
    
    void mostrarVideos() override {
        ImGui::Text("--- VIDEOS DISPONIBLES ---");
        for(size_t i = 0; i < videos.size(); i++) {
            ImGui::Text("%d. %s", (int)(i+1), videos[i].c_str());
        }
        ImGui::Text("-------------------------");
    }
    
    void mostrarImagen() override {
        ImGui::Text("--- IMAGEN/POSTER ---");
        ImGui::Text("Imagen: %s", imagen.c_str());
        ImGui::Text("--------------------");
    }
};

// Clase Catálogo
class Catalogo {
private:
    vector<ContenidoMultimedia*> contenido;

public:
    Catalogo() {
        // PELÍCULAS
        contenido.push_back(new Pelicula("La princesa Mononoke", 8.4, 134, "Fantasía/Aventura", "Hayao Miyazaki", 1997, "Poster con San y los espíritus del bosque"));
        contenido.push_back(new Pelicula("El viaje de Chihiro", 8.6, 125, "Fantasía/Aventura", "Hayao Miyazaki", 2001, "Poster de Chihiro en el mundo de los espíritus"));
        contenido.push_back(new Pelicula("Look Back", 8.1, 90, "Drama/Slice of Life", "Kiyotaka Oshiyama", 2021, "Poster de dos lesbianas"));
        contenido.push_back(new Pelicula("Star Wars: Episodio I - La amenaza fantasma", 6.5, 136, "Ciencia ficción", "George Lucas", 1999, "Poster con Darth Maul y Anakin"));
        contenido.push_back(new Pelicula("Star Wars: Episodio II - El ataque de los clones", 6.5, 142, "Ciencia ficción", "George Lucas", 2002, "Poster con Anakin y Padmé"));
        contenido.push_back(new Pelicula("Star Wars: Episodio III - La venganza de los Sith", 7.5, 140, "Ciencia ficción", "George Lucas", 2005, "Poster con Anakin y Obi-Wan luchando"));
        contenido.push_back(new Pelicula("Star Wars: Episodio IV - Una nueva esperanza", 8.6, 121, "Ciencia ficción", "George Lucas", 1977, "Poster clásico de Star Wars"));
        contenido.push_back(new Pelicula("Star Wars: Episodio V - El imperio contraataca", 8.7, 124, "Ciencia ficción", "Irvin Kershner", 1980, "Poster con Han Solo y Leia"));
        contenido.push_back(new Pelicula("Star Wars: Episodio VI - El retorno del Jedi", 8.3, 131, "Ciencia ficción", "Richard Marquand", 1983, "Poster con Luke y Darth Vader"));
                
        // SERIES
        contenido.push_back(new Serie("Jujutsu Kaisen", 8.7, 24, "Acción/Fantasía oscura", 2, 47, "Sunghoo Park", "Poster con Yuji Itadori y Sukuna"));
        contenido.push_back(new Serie("Pokémon", 7.5, 22, "Aventura/Fantasía", 25, 1200, "Kunihiko Yuyama", "Poster con Pikachu y Ash"));
        contenido.push_back(new Serie("Violet Evergarden", 8.8, 24, "Drama/Fantasía", 1, 13, "Taichi Ishidate", "Poster con violet"));
        contenido.push_back(new Serie("Kimetsu no Yaiba", 8.7, 24, "Acción/Fantasía oscura", 3, 55, "Haruo Sotozaki", "Poster con Tanjiro y Nezuko"));
        contenido.push_back(new Serie("Attack on Titan", 9.0, 24, "Acción/Fantasía oscura", 4, 87, "Tetsurō Araki", "Poster con Eren y los titanes"));
        contenido.push_back(new Serie("Blue Lock", 8.3, 24, "Deporte/Drama", 1, 24, "Tetsuaki Watanabe", "Poster con los jugadores de fútbol"));
        contenido.push_back(new Serie("Star Wars: The Clone Wars", 8.4, 22, "Ciencia ficción", 7, 133, "Dave Filoni", "Poster con Anakin y Ahsoka"));
        contenido.push_back(new Serie("Ann", 7.9, 45, "Drama/Thriller", 1, 10, "Unknown", "Poster de la niña pelirroja"));
        contenido.push_back(new Serie("Nadie nos va a extrañar", 8.1, 45, "Drama/Crimen", 1, 10, "Unknown", "Niños de mexico noventeros"));
        contenido.push_back(new Serie("Si la vida te da mandarinas", 7.8, 45, "Drama/Comedia", 1, 10, "Unknown", "un dulce k-drama"));
        contenido.push_back(new Serie("Goblin", 8.9, 70, "Fantasía/Romance", 1, 16, "Lee Eung-bok", "Poster del mejor k.drama de la historia"));
        contenido.push_back(new Serie("Alien Stage", 8.5, 15, "Ciencia ficción/Musical", 1, 6, "Unknown", "nose la sofi jsjsjs"));
    }
    
    ~Catalogo() {
        for(auto* item : contenido) {
            delete item;
        }
    }
    
    void mostrarCatalogo() {
        ImGui::Begin("Catálogo Netflix Piratón");
        ImGui::Text("===== CATALOGO NETFLIX PIRATON =====");
        for(size_t i = 0; i < contenido.size(); i++) {
            string label = to_string(i+1) + ". " + contenido[i]->getTitulo() + " ⭐ " + 
                           to_string(contenido[i]->getCalificacion()) + " | " + 
                           to_string(contenido[i]->getDuracion()) + " min | " + 
                           contenido[i]->getGenero();
            if (ImGui::Selectable(label.c_str())) {
                // Handle selection
            }
        }
        ImGui::Text("=================================");
        ImGui::End();
    }
    
    void seleccionarContenido(int opcion, bool& showDetails, ContenidoMultimedia*& selectedContent) {
        if(opcion < 1 || opcion > (int)contenido.size()) {
            ImGui::OpenPopup("Error");
            return;
        }
        
        selectedContent = contenido[opcion-1];
        showDetails = true;
    }
    
    void mostrarEstadisticas() {
        ImGui::Begin("Estadísticas");
        ImGui::Text("ESTADISTICAS DEL CATALOGO:");
        ImGui::Text("===============================");
        
        int peliculas = 0, series = 0;
        float promedioCalif = 0;
        int duracionTotal = 0;
        
        for(auto* item : contenido) {
            if(typeid(*item) == typeid(Pelicula)) {
                peliculas++;
            } else {
                series++;
            }
            promedioCalif += item->getCalificacion();
            duracionTotal += item->getDuracion();
        }
        
        promedioCalif /= contenido.size();
        
        ImGui::Text("Películas: %d", peliculas);
        ImGui::Text("Series: %d", series);
        ImGui::Text("Calificación promedio: %.1f/10", promedioCalif);
        ImGui::Text("Duración promedio: %d minutos", (duracionTotal/contenido.size()));
        ImGui::Text("Total de contenido: %d títulos", (int)contenido.size());
        ImGui::Text("===============================");
        ImGui::End();
    }

    void buscarPorGenero(const string& genero, vector<ContenidoMultimedia*>& resultados) {
        resultados.clear();
        for(auto* item : contenido) {
            if(item->getGenero().find(genero) != string::npos) {
                resultados.push_back(item);
            }
        }
    }

    vector<ContenidoMultimedia*>& getContenido() { return contenido; }
};

// Main application
int main(int, char**)
{
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Sistema de Streaming", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Application state
    Catalogo catalogo;
    bool show_catalog = true;
    bool show_details = false;
    bool show_stats = false;
    bool show_search = false;
    ContenidoMultimedia* selected_content = nullptr;
    char search_buffer[256] = "";
    vector<ContenidoMultimedia*> search_results;
    int selected_item = -1;

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Main Menu
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Menú")) {
                if (ImGui::MenuItem("Mostrar Catálogo")) {
                    show_catalog = true;
                    show_details = false;
                    show_stats = false;
                    show_search = false;
                }
                if (ImGui::MenuItem("Buscar por Género")) {
                    show_search = true;
                    show_catalog = false;
                    show_details = false;
                    show_stats = false;
                    search_buffer[0] = '\0';
                    search_results.clear();
                }
                if (ImGui::MenuItem("Estadísticas")) {
                    show_stats = true;
                    show_catalog = false;
                    show_details = false;
                    show_search = false;
                }
                if (ImGui::MenuItem("Salir")) {
                    glfwSetWindowShouldClose(window, true);
                }
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        // Show Catalog
        if (show_catalog) {
            ImGui::Begin("Catálogo Netflix Piratón");
            ImGui::Text("===== CATALOGO NETFLIX PIRATON =====");
            for(size_t i = 0; i < catalogo.getContenido().size(); i++) {
                string label = to_string(i+1) + ". " + catalogo.getContenido()[i]->getTitulo() + 
                               " ⭐ " + to_string(catalogo.getContenido()[i]->getCalificacion()) + 
                               " | " + to_string(catalogo.getContenido()[i]->getDuracion()) + 
                               " min | " + catalogo.getContenido()[i]->getGenero();
                if (ImGui::Selectable(label.c_str())) {
                    selected_item = (int)i + 1;
                    catalogo.seleccionarContenido(selected_item, show_details, selected_content);
                    show_catalog = false;
                }
            }
            ImGui::Text("=================================");
            ImGui::End();
        }

        // Show Details
        if (show_details && selected_content) {
            ImGui::Begin("Detalles del Contenido");
            selected_content->mostrarInfo();
            selected_content->mostrarImagen();
            selected_content->mostrarVideos();
            if (ImGui::Button("Reproducir Contenido")) {
                ImGui::OpenPopup("Reproduciendo");
            }
            if (ImGui::Button("Ver Videos Relacionados")) {
                selected_content->mostrarVideos();
            }
            if (ImGui::Button("Volver al Catálogo")) {
                show_details = false;
                show_catalog = true;
            }
            ImGui::End();

            if (ImGui::BeginPopup("Reproduciendo")) {
                ImGui::Text("Reproduciendo: %s...", selected_content->getTitulo().c_str());
                ImGui::Text("¡Disfruta tu contenido!");
                if (ImGui::Button("Cerrar")) {
                    ImGui::CloseCurrentPopup();
                }
                ImGui::EndPopup();
            }
        }

        // Show Search
        if (show_search) {
            ImGui::Begin("Buscar por Género");
            ImGui::Text("Géneros disponibles:");
            ImGui::Text("Acción, Drama, Comedia, Sci-Fi, Fantasía, Crimen, Romance, Horror, Thriller");
            ImGui::InputText("Género", search_buffer, IM_ARRAYSIZE(search_buffer));
            if (ImGui::Button("Buscar")) {
                catalogo.buscarPorGenero(search_buffer, search_results);
            }
            ImGui::Text("Resultados:");
            for(size_t i = 0; i < search_results.size(); i++) {
                string label = to_string(i+1) + ". " + search_results[i]->getTitulo() + 
                               " ⭐ " + to_string(search_results[i]->getCalificacion());
                if (ImGui::Selectable(label.c_str())) {
                    selected_content = search_results[i];
                    show_details = true;
                    show_search = false;
                }
            }
            if (search_results.empty() && search_buffer[0] != '\0') {
                ImGui::Text("No se encontraron resultados para ese género.");
            }
            if (ImGui::Button("Volver")) {
                show_search = false;
                show_catalog = true;
            }
            ImGui::End();
        }

        // Show Statistics
        if (show_stats) {
            catalogo.mostrarEstadisticas();
        }

        // Error Popup
        if (ImGui::BeginPopup("Error")) {
            ImGui::Text("Opción inválida. Por favor selecciona un número válido.");
            if (ImGui::Button("Cerrar")) {
                ImGui::CloseCurrentPopup();
            }
            ImGui::EndPopup();
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}