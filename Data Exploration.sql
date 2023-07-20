Select *
From PortofolioProject..CovidDeaths
Where continent is not null

--comparing total cases with total Deaths
Select location,date,total_cases,total_deaths, (total_deaths/total_cases)*100 as DeathPercentage
From PortofolioProject..CovidDeaths
Where continent is not null
Order By 1,2

Select date,location,total_cases,population, (total_cases/population)*100 as DeathPercentage
From  PortofolioProject..CovidDeaths
--Where location like '%states%'
Where continent is not null
Order By 1,2

Select location,population,Max(total_cases) AS MaxCases,Max((total_cases/population)*100) AS MaxPercentage
from PortofolioProject..CovidDeaths
Where continent is not null
Group by location,population
Order by MaxCases desc

Select location,Max(cast(total_deaths as int)) as TotalDeathsCount
From PortofolioProject..CovidDeaths
Where continent is not null
Group by location
order by TotalDeathsCount desc
--Global Numbers

Select date, SUM(new_cases) as TotalCases, SUM(cast(new_deaths as int)) as TotalDeaths,SUM(cast(new_deaths as int))/SUM(new_cases)*100 as PercentageDeath
From PortofolioProject..CovidDeaths
where continent is not null
group by date
order by 1,2

--covidVacccinations table 
select * from PortofolioProject..CovidVaccinations
--join tables
Select dea.continent,dea.date,dea.location,dea.population,vac.new_vaccinations
From PortofolioProject..CovidDeaths as dea
Join PortofolioProject..CovidVaccinations as vac
ON dea.date = vac.date
and dea.location = vac.location 
where dea.continent is not null
order by 2,3
--Knowing the max of vacinated people in each country
Select dea.location,dea.date,dea.continent,dea.population,vac.new_vaccinations,SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) as RollingPeopleVaccinated
From PortofolioProject..CovidDeaths as dea
Join PortofolioProject..CovidVaccinations as vac
ON dea.date = vac.date
and dea.location = vac.location 
where dea.continent is not null
order by 1,2
--using  a cte to know the percentage of vaccinated people in each country
WITH PopvsVac(continent,date,location,population,new_vaccinations,RollingPeopleVaccinated)
AS
(Select dea.location,dea.date,dea.continent,dea.population,vac.new_vaccinations,SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) as RollingPeopleVaccinated
From PortofolioProject..CovidDeaths as dea
Join PortofolioProject..CovidVaccinations as vac
ON dea.date = vac.date
and dea.location = vac.location 
where dea.continent is not null
)
Select *,(RollingPeopleVaccinated/population)*100 as PercentPopVaccinated
From PopvsVac
--creating views to store data for visualizations 
create view PopvsVac as 
Select dea.location,dea.date,dea.continent,dea.population,vac.new_vaccinations,SUM(CONVERT(int,vac.new_vaccinations)) OVER (PARTITION BY dea.location order by dea.location, dea.date) as RollingPeopleVaccinated
From PortofolioProject..CovidDeaths as dea
Join PortofolioProject..CovidVaccinations as vac
ON dea.date = vac.date
and dea.location = vac.location 
where dea.continent is not null
