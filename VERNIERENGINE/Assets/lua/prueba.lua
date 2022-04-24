prueba = {
    entities = {"mono", "suelo"}
}

pruebaBala = {
    entities = {"bala"}
}

mono={
    Active = true,
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
        file = "prueba.lua",
        name = "pruebaBala",
        prefabName = "bala"
    }
}


suelo={
    Active = true,
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
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "0,0,0",
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
    }
}