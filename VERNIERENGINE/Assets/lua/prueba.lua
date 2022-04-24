prueba = {
    entities = {"mono", "suelo", "boton"}
}

mono={
    Active = true,
    Listener = true,
    Components = {"Transform","MeshRenderer", "Rigidbody", "Shoot"},

    Transform = {
        Position = "0,100,0",
        Scale = "10,10,10",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Sphere"
    },
    Rigidbody = {
        Type = "Sphere",
        Mass = "1",
        Radius = "10",
        Position = "0,0,0"
    },
    Shoot = {
        entity = "mono",
        file = "prueba.lua",
        name = "bala",
        prefabName = "bala"
    }
}


suelo={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "0,0,0",
        Scale = "10,10,10",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Plane"
    },
    Rigidbody = {
        Type = "Box",
        Mass = "1",
        Scale = "1,10,10",
        Position = "0,0,0"
    }
    
}

bala={
    Active = true,
    Listener = false,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "-150,-50,0",
        Scale = "5,5,5",
        Rotation = "0,0,0"
    },
    
    MeshRenderer = {
        Mesh = "Sphere"
    },
    Rigidbody = {
        Type = "Sphere",
        Mass = "1",
        Radius = "10",
        Position = "0,0,0"
    }
}

boton={
    Active = true;
    Components = {"Transform", "Button1"},

    Transform = {
        Position = "300, 200, 0",
        Scale = "1,1,1",
        Rotation = "0,0,0"
    },

    Button1 = {
        Callback = "CambioEscena"
    }
}