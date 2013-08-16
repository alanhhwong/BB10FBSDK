import bb.cascades 1.0

Page {
    Container {
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
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
        }
        Divider {
        }
        Container {
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
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

        Divider {
        }
        Button {
            text: "Post Test Message"
            onClicked: {
                app.publishPost();
            }
        }
        Button {
            text: "Post Test Message With Image URL"
            onClicked: {
                app.publishPostWithImageUrl();
            }
        }
        Divider {
        }
        Container {
            leftPadding: 20
            rightPadding: 20
            layout: StackLayout {
                orientation: LayoutOrientation.LeftToRight
            }
            Label {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 3
                }
                verticalAlignment: VerticalAlignment.Center
                text: "Console Logging"
            }
            Button {
                layoutProperties: StackLayoutProperties {
                    spaceQuota: 1
                }
                text: "Clear"
                onClicked: {
                    app.clearLogs();
                }
            }
        }
        Container {
            layoutProperties: StackLayoutProperties {
                spaceQuota: 1
            }
            ScrollView {
                verticalAlignment: VerticalAlignment.Fill
                Label {
                    verticalAlignment: VerticalAlignment.Fill
                    objectName: "log"
                    multiline: true
                }
            }
        }
    }
}
