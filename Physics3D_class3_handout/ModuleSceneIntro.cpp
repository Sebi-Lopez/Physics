#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// TODO 3: create a sphere in the world with a primitive
	// and create a physics body for it. Remember to render it in Update()
	sphere = new Sphere(1); 
	sphere->SetPos(0, 10, 0);
	sphere_body = App->physics->AddBody(*sphere);
	// TODO 5: Add this module to the list of collision listeners
	sphere_body->collision_listeners.add(this); 

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// TODO 5: ... and define it for the ModuleScenario. Set the ball
// in red if it happens using is color property

void ModuleSceneIntro::OnCollision(PhysBody3D * body1, PhysBody3D * body2)
{
	sphere->color = Red;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	sphere->Render();
	// TODO 4: update the transform of the shape to meet the
	// physics one
	sphere_body->GetTransform(sphere->transform.M);

	
	return UPDATE_CONTINUE;
}



