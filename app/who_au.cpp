#include "who_au.h"

WhoAU::WhoAU(IUserInterface *ui)
{
    setUi(ui);
}

void WhoAU::setUi(IUserInterface *ui)
{
    _ui = ui;

//    _ui->requireAuth();
}

void WhoAU::start()
{
//    _ui->requireAuth();
    _ui->requireUserWork();
}

void WhoAU::authentication(
        std::string email, std::string pass)
{
    nlohmann::json response_json =
            nlohmann::json::parse(
                cloud.authentication(email, pass));

    if (cloud.isLogged())
    {
        _ui->requireUserWork();
    }
    else
    {
        _ui->errWhenAuth(response_json["message"]);
    }
}











