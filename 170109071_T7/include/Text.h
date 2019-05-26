#ifndef GAME_H
    #include "Game.h"
#endif

#ifndef TEXT_H
    #define TEXT_H
    #include "Component.h"

    class Text : public Component{
        public:
            enum TextStyle{SOLID,SHADED,BLENDED};
            Text(GameObject& associated,std::string fontFile,int fontSize,TextStyle style,std::string text,SDL_Color color);
            ~Text();

            void Update(float dt);
            void Render();
            bool Is(std::string type);

            void SetText(std::string text);
            void SetColor(SDL_Color);
            void SetStyle(TextStyle style);
            void SetFontFile(std::string fontFile);
            void SetFontSize(int fontSize);
        private:
            void RemakeTexture();
            std::shared_ptr<TTF_Font> font;
            SDL_Texture *texture;
            std::string text;
            TextStyle style;
            std::string fontFile;
            int fontSize;
            SDL_Color color;
    };

#endif;