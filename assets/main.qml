import bb.cascades 1.0

Page {
    Container {
        //Todo: fill me with QML
        Button {
            text: "Log In"
            onClicked: {
                app.logIn();
            }
        }
        Button {
            text: "Log Out"
            onClicked: {
                app.logOut();
            }
        }
        Button {
            text: "Get Profile"
            onClicked: {
                app.getUserProfile();
            }
        }
        Button {
            text: "Get User Friends"
            onClicked: {
                app.getUserFriends();
            }
        }
    }
}
