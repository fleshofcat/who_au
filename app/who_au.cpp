#include "who_au.h"

WhoAU::WhoAU(IUserInterface *ui)
{
    setUi(ui);
}

void WhoAU::setUi(IUserInterface *ui)
{
    this->ui = ui;
}

void WhoAU::start()
{
    ui->showAuth();
}

void WhoAU::authentication(
        std::string email, std::string pass)
{
    nlohmann::json response_json =
            nlohmann::json::parse(
                cloud.authentication(email, pass));

    if (cloud.isLogged())
    {
        ui->showUserWorkspace();
    }
    else
    {
        ui->showAuthError(response_json["message"]);
    }
}

void WhoAU::detectFace(std::list<string> imagePaths)
{
    for (auto path : imagePaths)
    {
        if (!loadedFiles.contains(path))
        {
            loadedFiles.insert(std::pair
                               <string, string>(path, ""));
        }
    }

    ui->showCurrentResult(loadedFiles);

    for (auto image = loadedFiles.begin(); image != loadedFiles.end(); ++image)
    {
        if (image->second.empty()) // if unhandled
        {
            image->second = sendFile(image->first);
        }

        ui->showCurrentResult(loadedFiles);
    }

}

std::string WhoAU::sendFile(string imagePath)
{
    // TODO conversation

    vector<char> jpegBin;

    ifstream file(imagePath);

    file.seekg (0, file.end);
    auto size = file.tellg();
    file.seekg (0, file.beg);

    jpegBin.resize((unsigned long)(size));

    file.read(jpegBin.data(), size);
    file.close();


    return cloud.detectImage(jpegBin);
}



























