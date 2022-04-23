prueba = {
    entities = {"entidad1"}
}

pruebaBala = {
    entities = {"bala"}
}

entidad1={
    Active = true,
    Components = {"Transform","MeshRenderer", "Rigidbody", "Shoot"},

    Transform = {
        Position = "150,0,0",
        Scale = "10,10,10",
        Rotation = "0,0,0"
    },
	
	MeshRenderer = {
        Mesh = "Cube"
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