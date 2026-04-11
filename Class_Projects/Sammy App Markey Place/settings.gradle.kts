pluginManagement {
    repositories {
        gradlePluginPortal()
        google()
        mavenCentral()
    }
    repositories {
        google {
            content {
                includeGroupByRegex("com\\.android.*")
                includeGroupByRegex("com\\.google.*")
                includeGroupByRegex("androidx.*")
            }
        }
        mavenCentral()
        gradlePluginPortal()
    }
}
dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
        google()
        mavenCentral()
    }
}

rootProject.name = "Sammy Marketplace app"
include(":app")



dependencyResolutionManagement {
    repositories {
        google()
        mavenCentral()
    }
}