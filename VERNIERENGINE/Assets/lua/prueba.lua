prueba = {
    entities = {"entidad1"}
}

entidad1={
    Active = true,
    Components = {"Transform","MeshRenderer", "Rigidbody"},

    Transform = {
        Position = "-300,0,0",
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
    }
}